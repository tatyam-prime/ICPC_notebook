---
title: KMP 法 (Knuth–Morris–Pratt algorithm)
documentation_of: //src/string/KMP.hpp
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/KMP.h)

## 使い方

- `vector<ll> KMP(string s)`：$\text{kmp}[i] := \max\\{ l ≤ i \mid s[:l] = s[(i+1)-l:i+1] \\}$ で定義される配列 $\text{kmp}$ を求める

$O(n)$ 時間
