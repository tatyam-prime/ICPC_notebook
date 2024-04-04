---
title: Suffix Array
documentation_of: //src/string/SuffixArray.hpp
---
- 参考実装：[kactl](https://github.com/kth-competitive-programming/kactl/blob/431a6ef4ec6c04cf4c17e065089b7c4d451ea9cf/content/strings/SuffixArray.h)

## 使い方

- `pair<vector<ll>, vector<ll>> SA(string s)`：文字列 $s$ の Suffix Array と LCP Array の組を返す．
    - Suffix Array：`[0, 1, …, n-1].sort(key=(i => s[i:]))`
    - LCP Array：`lcp[i] = LCP(s[sa[i]:], s[sa[i+1]:])`
    - `lim` には $s$ の文字種の最大値を指定する
    - $O(n \log n)$ 時間

## ベンチマーク

| $n = 2^{20}$ の SA + LCP | 所要時間 |
| --- | --- |
| これ | 310 ms |
| [AC Library](https://github.com/atcoder/ac-library/blob/d8ca7f26686f6c78d15d13ca438ea866526e87fb/atcoder/string.hpp) | 100 ms |
