#!/usr/bin/env python3
"""notebook.pdf から行が欠落していないかを調べる (#3)

PDF のテキストを段ごとの読み順で取り出し、build/notebook.html の本文と照合する。
- ファイル名・md5・コードは、読み順どおり完全に一致することを確認する
- .md の内容は表の読み順が HTML と異なるため、数式以外の文字がそのファイルの範囲に含まれることを確認する
- 本文のテキストがヘッダー領域や下余白に入り込んでいないことを確認する
  (段からあふれた行は、印刷時に次ページの上端へ送られてクリップされる)

usage: python3 build/check_pdf.py [notebook.pdf] [build/notebook.html]
pdftotext (poppler-utils) が必要。問題があれば終了コード 1 を返す。
"""
import collections
import html
import html.parser
import os
import re
import subprocess
import sys
import unicodedata
import xml.etree.ElementTree as ET

MM = 72 / 25.4  # 1mm (pt)


def norm(s):
    return re.sub(r"\s+", "", unicodedata.normalize("NFKC", s))


def length_pt(v):
    m = re.fullmatch(r"([\d.]+)(mm|cm|in|pt|px)?", v)
    if not m:
        raise ValueError(v)
    unit = {"mm": MM, "cm": 10 * MM, "in": 72, "pt": 1, "px": 0.75, None: 0.75}[m.group(2)]
    return float(m.group(1)) * unit


def page_margins(css):
    """@page の margin (上, 下) を pt で返す。読めなければ None"""
    m = re.search(r"@page\s*\{[^{}]*?margin\s*:\s*([^;}]+)", css)
    if not m:
        return None
    try:
        v = [length_pt(x) for x in m.group(1).split()]
    except ValueError:
        return None
    if not 1 <= len(v) <= 4:
        return None
    top = v[0]
    bottom = v[2] if len(v) >= 3 else v[0]
    return top, bottom


def read_text(path):
    try:
        with open(path, encoding="utf-8") as f:
            return f.read()
    except OSError:
        return ""


class Word:
    def __init__(self, page, col, x, y0, y1, text):
        self.page, self.col, self.x, self.y0, self.y1, self.text = page, col, x, y0, y1, text
        self.cy = (y0 + y1) / 2
        self.h = y1 - y0


def pdf_words(pdf):
    out = subprocess.run(["pdftotext", "-bbox", pdf, "-"], check=True,
                         capture_output=True, text=True, encoding="utf-8").stdout
    out = re.sub(r"<!DOCTYPE[^>]*>", "", out).replace('xmlns="http://www.w3.org/1999/xhtml"', "")
    pages = []
    for page in ET.fromstring(out).iter("page"):
        W, H = float(page.get("width")), float(page.get("height"))
        words = []
        for w in page.iter("word"):
            x0, y0, y1 = float(w.get("xMin")), float(w.get("yMin")), float(w.get("yMax"))
            words.append(Word(len(pages) + 1, 0 if x0 < W / 2 else 1, x0, y0, y1, w.text or ""))
        pages.append((W, H, words))
    return pages


def reading_order(words):
    """段ごとに、縦方向の中心が近い単語を 1 行にまとめ、行内は左から並べる"""
    lines = []
    for col in (0, 1):
        cur = []
        for w in sorted((w for w in words if w.col == col), key=lambda w: w.cy):
            if cur and w.cy - cur[0].cy > 0.5 * min(cur[0].h, w.h):
                lines.append(sorted(cur, key=lambda w: w.x))
                cur = []
            cur.append(w)
        if cur:
            lines.append(sorted(cur, key=lambda w: w.x))
    return lines


class Expected(html.parser.HTMLParser):
    """notebook.html の本文 (目次より後) を [(kind, text, filename)] にする
    kind: "strict" (読み順どおり一致) / "md" (.md の内容)"""
    BLOCKS = {"p", "li", "td", "th", "h1", "h2", "h3", "h4", "h5", "h6", "pre", "div", "tr"}

    def __init__(self):
        super().__init__(convert_charrefs=True)
        self.started = False
        self.stack = []  # (tag, is_md, is_skip)
        self.items = []
        self.filename = None

    def in_md(self):
        return any(md for _, md, _ in self.stack)

    def in_skip(self):
        return any(skip for _, _, skip in self.stack)

    def handle_starttag(self, tag, attrs):
        a = dict(attrs)
        if tag == "h2" and "id" in a and "section" not in (a.get("class") or ""):
            self.filename = a["id"]
        is_md = tag == "div" and "content-md" in (a.get("class") or "").split()
        is_skip = tag in ("mjx-container", "svg", "style", "script")
        if tag not in ("br", "img", "hr", "meta", "link", "input"):
            self.stack.append((tag, is_md, is_skip))
        if tag in self.BLOCKS:
            self.items.append(("break", "", self.filename))

    def handle_endtag(self, tag):
        if tag == "nav":
            self.started = True
        for i in range(len(self.stack) - 1, -1, -1):
            if self.stack[i][0] == tag:
                del self.stack[i:]
                break
        if tag in self.BLOCKS:
            self.items.append(("break", "", self.filename))

    def handle_data(self, data):
        if not self.started or self.in_skip():
            return
        self.items.append(("md" if self.in_md() else "strict", data, self.filename))


def main():
    pdf = sys.argv[1] if len(sys.argv) > 1 else "notebook.pdf"
    src = sys.argv[2] if len(sys.argv) > 2 else "build/notebook.html"
    css_dir = os.path.dirname(src)
    errors = []

    # ---- PDF のテキスト (ヘッダーを除いた本文) を読み順に並べる ----
    margins = page_margins(read_text(os.path.join(css_dir, "base.css")))
    m = re.search(r'@top-left\s*\{\s*content:\s*"((?:[^"\\]|\\.)*)"', read_text(os.path.join(css_dir, "notebook.css")))
    header_words = set(m.group(1).split() if m else []) | {"Page", "of"}
    if margins is None:
        print("warning: @page の margin を読めないため、余白へのはみ出しは確認しません")

    stream = []  # (正規化した文字列, page, col, y)
    for W, H, words in pdf_words(pdf):
        body = []
        for w in words:
            if margins and w.cy < margins[0]:  # ヘッダー領域
                if w.text not in header_words and not w.text.isdigit():
                    errors.append(f"page {w.page}: ヘッダー領域に本文の文字列 {w.text!r} があります (前のページからあふれた行の可能性)")
                continue
            if margins and w.cy > H - margins[1]:
                errors.append(f"page {w.page}: 下余白に本文の文字列 {w.text!r} があります (段からあふれています)")
            body.append(w)
        for line in reading_order(body):
            stream.append((norm("".join(w.text for w in line)), line[0].page, line[0].col, line[0].y0))
    S = "".join(t for t, *_ in stream)
    where = []  # S の各文字がどこにあるか
    for t, p, c, y in stream:
        where += [(p, c, y)] * len(t)

    def at(pos):
        p, c, y = where[min(pos, len(where) - 1)] if where else (0, 0, 0)
        return f"page {p} {'左右'[c]}段 y={y:.0f}pt"

    # ---- HTML の本文を読む ----
    parser = Expected()
    parser.feed(read_text(src))
    items = parser.items
    if not any(k == "strict" and norm(t) for k, t, _ in items):
        print(f"error: {src} から本文を読み取れません")
        return 1

    # 本文の開始位置 (目次にはない md5 を含む先頭部分で探す)
    head = ""
    for k, t, _ in items:
        if k == "md":
            break
        head += norm(t) if k == "strict" else ""
        if len(head) >= 40:
            break
    pos = S.find(head)
    if pos < 0:
        print(f"error: PDF の中に本文の先頭 {head!r} が見つかりません")
        return 1

    # strict はそのまま、md はファイルごとにまとめる
    groups = []  # ("strict", [lines], file) / ("md", [fragments], file)
    for k, t, f in items:
        if k == "break":
            if groups and groups[-1][0] == "md":
                groups[-1][1].append("")
            continue
        if not groups or groups[-1][0] != k or groups[-1][2] != f:
            groups.append((k, [""], f))
        if k == "strict":
            parts = t.split("\n")
            groups[-1][1][-1] += parts[0]
            groups[-1][1].extend(parts[1:])
        else:
            groups[-1][1][-1] += t

    def next_strict(i):
        for k, lines, _ in groups[i + 1:]:
            if k == "strict":
                for line in lines:
                    if norm(line):
                        return norm(line)
        return None

    for i, (kind, lines, f) in enumerate(groups):
        if kind == "strict":
            for line in lines:
                n = norm(line)
                if not n:
                    continue
                if S.startswith(n, pos):
                    pos += len(n)
                    continue
                k = S.find(n, pos, pos + max(400, 4 * len(n)))
                if k >= 0:
                    errors.append(f"{f}: {at(pos)} に余分な文字列 {S[pos:k]!r} があります")
                    pos = k + len(n)
                else:
                    errors.append(f"{f}: {line.strip()!r} が {at(pos)} 付近から欠落しています")
        else:
            # 次の strict の手前までを、この .md の範囲とみなす
            nxt = next_strict(i)
            end = S.find(nxt, pos) if nxt else len(S)
            if end < 0:
                end = len(S)
            have = collections.Counter(S[pos:end])
            for frag in lines:
                # (旧方式の HTML のように) $...$ が残っていたら、数式なので除く
                need = collections.Counter(norm(re.sub(r"\$[^$]*\$", "", frag)))
                if need - have:
                    errors.append(f"{f}: {frag.strip()!r} の一部が {at(pos)} 以降から欠落しています")
                have -= need
            pos = end

    if errors:
        print(f"{pdf}: {len(errors)} 件の問題が見つかりました")
        for e in errors:
            print("  " + e)
        return 1
    print(f"{pdf}: 欠落は見つかりませんでした")
    return 0


if __name__ == "__main__":
    sys.exit(main())
