# ICPC_notebook

[![Actions Status](https://github.com/tatyam-prime/ICPC_notebook/workflows/verify/badge.svg)](https://github.com/tatyam-prime/ICPC_notebook/actions) [![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=document+&color=brightgreen&logo=github)](https://tatyam-prime.github.io/ICPC_notebook/)

- CSS 組版で、ファイルを置くだけで PDF が簡単に作れる、ICPC 用ライブラリのすごいテンプレート
- かつ、みんなでつくる最強の ICPC 用ライブラリ (予定)
- [ライブラリのドキュメント](https://tatyam-prime.github.io/ICPC_notebook/)
- [ライブラリをまとめたページ](https://tatyam-prime.github.io/ICPC_notebook/notebook.html)
- [ライブラリをまとめた PDF](https://tatyam-prime.github.io/ICPC_notebook/notebook.pdf)

## private なコピーを作るには

1. 新規 private repository を作る
2. repository の Settings -> Actions -> Workflow permissions を Read and Write に設定
3. `git clone https://github.com/tatyam-prime/ICPC_notebook.git && cd ICPC_notebook`
4. `git remote set-url origin {your_private_repository_url}`
5. `git commit -m "test" --allow-empty && git push`
6. workflow が動くことを確認
7. [README.txt](README.txt) をいい感じに修正

## 内容を変更するには

1. [src/\*/\*](src/) の中身を変更する
2. [build/build.js](build/build.js) の設定項目を変更する
3. commit & push

## 手元で動かすには

### 事前にインストールするもの

- node.js (v18 以上)
- npm
    - `brew install node` / <https://learn.microsoft.com/ja-jp/windows/dev-environment/javascript/nodejs-on-wsl>
- clang-format
    - `brew install clang-format` / `sudo apt install clang-format`
- vivliostyle
    - `npm install -g @vivliostyle/cli`
- その他依存関係
    - `npm install`
- (使うなら) oj-verify
    - `pip3 install online-judge-verify-helper`

### PDF を生成する

1. `make build`

### oj-verify で verify

1. `make verify`

### oj-verify ページを生成

1. `make serve`

