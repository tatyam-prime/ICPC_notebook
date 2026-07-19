---
title: Line Container (CHT)
documentation_of: //src/data-structure/LineContainer.hpp
---

- 参考実装：[kactl](https://github.com/kth-competitive-programming/kactl/blob/96ad8abb2082a909b8b1535d219b5232a38c9a10/content/data-structures/LineContainer.h)

## 使い方

直線の追加と，ある $x$ における最大値の取得が $O(\log n)$ / クエリ で行えるデータ構造です．

- `LineContainer()`：空の LineContainer を作る
- `void add(ll a, ll b)`：直線 $y = ax + b$ を追加する
- `ll max(ll x)`：ある $x$ における最大値を求める

時間計算量: 追加された直線の本数を $n$ として，$O(\log n)$ / クエリ

## 実装について

- `Line::p` は，この直線が最大値を取ることのできる最大の $x$ を切り捨てた値です．整数除算によって直線が要るかどうか判断しているため，(`max(x)` の値がオーバーフローしないのであれば) <span style="color: firebrick;"> $|a|, |b| \le 10^{18}$ の直線を追加してもオーバーフローの心配はありません．</span>
