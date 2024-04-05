---
title: Manacher's algorithm
documentation_of: //src/string/Manacher.hpp
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/Manacher.h)

## 使い方

- `array<vector<ll>, 2> Z(const string& s)`：$Z[i] := \text{LCP}(s, s[i:])$ で定義される配列 $Z$ を求める

$O(n)$ 時間
