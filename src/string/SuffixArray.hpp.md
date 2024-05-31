---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/LCP.test.cpp
    title: test/string/LCP.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/string/SuffixArray.test.cpp
    title: test/string/SuffixArray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/SuffixArray.hpp\"\n// returns pair{sa, lcp}\n\
    // sa \u9577\u3055 n : s[sa[0]:] < s[sa[1]:] < \u2026 < s[sa[n-1]:]\n// lcp \u9577\
    \u3055 n-1 : lcp[i] = LCP(s[sa[i]:], s[sa[i+1]:])\nauto SA(string s) {\n   ll\
    \ n = sz(s) + 1, lim = 256;\n   // assert(lim > ranges::max(s));\n   vector<ll>\
    \ sa(n), lcp(n), x(all(s) + 1), y(n), ws(max(n, lim)), rk(n);\n   iota(all(sa),\
    \ 0);\n   for(ll j = 0, p = 0; p < n; j = max(1LL, j * 2), lim = p) {\n      p\
    \ = j;\n      iota(all(y), n - j);\n      rep(i, 0, n) if(sa[i] >= j) y[p++] =\
    \ sa[i] - j;\n      fill(all(ws), 0);\n      rep(i, 0, n) ws[x[i]]++;\n      rep(i,\
    \ 1, lim) ws[i] += ws[i - 1];\n      for(ll i = n; i--;) sa[--ws[x[y[i]]]] = y[i];\n\
    \      swap(x, y);\n      p = 1;\n      x[sa[0]] = 0;\n      rep(i, 1, n) {\n\
    \         ll a = sa[i - 1], b = sa[i];\n         x[b] = (y[a] == y[b] && y[a +\
    \ j] == y[b + j]) ? p - 1 : p++;\n      }\n   }\n   rep(i, 1, n) rk[sa[i]] = i;\n\
    \   for(ll i = 0, k = 0; i < n - 1; lcp[rk[i++]] = k) {\n      if(k) k--;\n  \
    \    while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;\n   }\n   sa.erase(begin(sa));\n\
    \   lcp.erase(begin(lcp));\n   return pair{sa, lcp};\n}\n"
  code: "// returns pair{sa, lcp}\n// sa \u9577\u3055 n : s[sa[0]:] < s[sa[1]:] <\
    \ \u2026 < s[sa[n-1]:]\n// lcp \u9577\u3055 n-1 : lcp[i] = LCP(s[sa[i]:], s[sa[i+1]:])\n\
    auto SA(string s) {\n   ll n = sz(s) + 1, lim = 256;\n   // assert(lim > ranges::max(s));\n\
    \   vector<ll> sa(n), lcp(n), x(all(s) + 1), y(n), ws(max(n, lim)), rk(n);\n \
    \  iota(all(sa), 0);\n   for(ll j = 0, p = 0; p < n; j = max(1LL, j * 2), lim\
    \ = p) {\n      p = j;\n      iota(all(y), n - j);\n      rep(i, 0, n) if(sa[i]\
    \ >= j) y[p++] = sa[i] - j;\n      fill(all(ws), 0);\n      rep(i, 0, n) ws[x[i]]++;\n\
    \      rep(i, 1, lim) ws[i] += ws[i - 1];\n      for(ll i = n; i--;) sa[--ws[x[y[i]]]]\
    \ = y[i];\n      swap(x, y);\n      p = 1;\n      x[sa[0]] = 0;\n      rep(i,\
    \ 1, n) {\n         ll a = sa[i - 1], b = sa[i];\n         x[b] = (y[a] == y[b]\
    \ && y[a + j] == y[b + j]) ? p - 1 : p++;\n      }\n   }\n   rep(i, 1, n) rk[sa[i]]\
    \ = i;\n   for(ll i = 0, k = 0; i < n - 1; lcp[rk[i++]] = k) {\n      if(k) k--;\n\
    \      while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;\n   }\n   sa.erase(begin(sa));\n\
    \   lcp.erase(begin(lcp));\n   return pair{sa, lcp};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/SuffixArray.hpp
  requiredBy: []
  timestamp: '2024-05-31 19:01:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/LCP.test.cpp
  - test/string/SuffixArray.test.cpp
documentation_of: src/string/SuffixArray.hpp
layout: document
title: Suffix Array
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
