---
title: Z Algorithm
documentation_of: //src/string/Zalgorithm.hpp
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/KMP.h)

## 使い方

- `vector<ll> Z(string s)`：$Z[i] := \text{LCP}(s, s[i:])$ で定義される配列 $Z$ を求める
    - $O(n)$ 時間

## 使い方 (応用編)

- 文字列 $s$ の部分文字列に $t$ が現れるか判定：$\text{Z}(t + s)$ の後ろ $\text{sz}(s)$ 個に $\text{sz}(t)$ 以上があるか
- 文字列 $s$ の最小周期：$\text{Z}(s + s)$ の $1$ 要素目以降で，はじめて $\text{sz}(s)$ 以上が出現する位置

