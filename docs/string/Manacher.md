---
title: Manacher's algorithm
documentation_of: //src/string/Manacher.hpp
---
- 参考実装：[ei1333 (Luzhiled's memo)](https://ei1333.github.io/luzhiled/snippets/string/manacher.html)

## 使い方

- `vector<ll> manacher(string s)`：文字列 $s$ の長さを $n$ として，長さ $n$ の整数列 $r$ を返す．$r[i]$ は $s[i]$ を中心とする回文半径で，$s[i - r[i]]$ から $s[i + r[i]]$ までが回文であることを表す．
- 文字と文字の間を中心とする回文半径も知りたいときは，両端を含めた境界 ($N + 1$ 個) に適当な文字 1 種類を挿入しておく．返される値は，挿入前の文字列における回文直径${} + 1$ (すなわち，極大な回文の長さ${} + 1$) になる．

$O(n)$ 時間
