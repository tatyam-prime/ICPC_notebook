---
title: Z Algorithm
documentation_of: //src/string/Zalgorithm.hpp
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/KMP.h)

## 使い方

- `vector<ll> Z(const string& s)`：$Z[i] := \text{LCP}(s, s[i:])$ で定義される配列 $Z$ を求める

$O(n)$ 時間
