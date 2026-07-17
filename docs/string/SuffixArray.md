---
title: Suffix Array
documentation_of: //src/string/SuffixArray.hpp
---
- written by: tatyam
- Suffix Array: prefix doubling
- LCP Array: Kasai's algorithm

## 使い方

- `pair<vector<ll>, vector<ll>> SA(string s)`：文字列 $s$ の Suffix Array と LCP Array の組を返す．
    - Suffix Array：`[0, 1, …, n-1].sort(key=(i => s[i:]))`
    - LCP Array：`lcp[i] = LongestCommonPrefix(s[sa[i]:], s[sa[i+1]:])`
    - $O(n \log n)$ 時間

## ベンチマーク

環境: AtCoder (2026)

| $n = 2^{20}$ の SA + LCP | 所要時間 |
| --- | --- |
| これ | 188 ms |
| [AC Library](https://github.com/atcoder/ac-library/blob/d8ca7f26686f6c78d15d13ca438ea866526e87fb/atcoder/string.hpp) | 97 ms |
