# ICPC_notebook

[![Actions Status](https://github.com/tatyam-prime/ICPC_notebook/workflows/verify/badge.svg)](https://github.com/tatyam-prime/ICPC_notebook/actions) [![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=document+&color=brightgreen&logo=github)](https://tatyam-prime.github.io/ICPC_notebook/)

- CSS 組版で、ファイルを置くだけで PDF が簡単に作れる、ICPC 用ライブラリのすごいテンプレート
- かつ、みんなでつくる最強の ICPC 用ライブラリ (予定)
- [ライブラリのドキュメント](https://tatyam-prime.github.io/ICPC_notebook/)
- [ライブラリをまとめたページ](https://tatyam-prime.github.io/ICPC_notebook/notebook.html)
- [ライブラリをまとめた PDF](https://tatyam-prime.github.io/ICPC_notebook/notebook.pdf)

#### 事前にインストールするもの

- node.js (v18 以上)
- npm
    - `brew install node` / <https://qiita.com/nouernet/items/d6ad4d5f4f08857644de>
- clang-format
    - `npm install -g clang-format`
- vivliostyle
    - `npm install -g @vivliostyle/cli`
- その他依存関係
    - `npm install`
- (使うなら) oj-verify
    - `pip3 install online-judge-verify-helper`

## PDF の生成方法

1. `make build`

## 内容の変更方法

1. [src/\*/\*](src/) の中身を変更する
2. [build/build.js](build/build.js) の設定項目を変更する
3. `make build`

