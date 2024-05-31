---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/Zalgorithm.test.cpp
    title: test/string/Zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/Zalgorithm.hpp\"\n// Z[i] := LCP(s, s[i:])\n\
    // abacaba -> 7010301\nauto Z(const string& s) {\n   vector<ll> z(sz(s), sz(s));\n\
    \   ll l = -1, r = -1;\n   rep(i, 1, sz(s)) {\n      z[i] = i >= r ? 0 : min(r\
    \ - i, z[i - l]);\n      while(i + z[i] < sz(s) && s[i + z[i]] == s[z[i]]) z[i]++;\n\
    \      if(i + z[i] > r) {\n         l = i;\n         r = i + z[i];\n      }\n\
    \   }\n   return z;\n}\n"
  code: "// Z[i] := LCP(s, s[i:])\n// abacaba -> 7010301\nauto Z(const string& s)\
    \ {\n   vector<ll> z(sz(s), sz(s));\n   ll l = -1, r = -1;\n   rep(i, 1, sz(s))\
    \ {\n      z[i] = i >= r ? 0 : min(r - i, z[i - l]);\n      while(i + z[i] < sz(s)\
    \ && s[i + z[i]] == s[z[i]]) z[i]++;\n      if(i + z[i] > r) {\n         l = i;\n\
    \         r = i + z[i];\n      }\n   }\n   return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Zalgorithm.hpp
  requiredBy: []
  timestamp: '2024-05-31 15:50:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/Zalgorithm.test.cpp
documentation_of: src/string/Zalgorithm.hpp
layout: document
title: Z Algorithm
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/KMP.h)

## 使い方

- `vector<ll> Z(const string& s)`：$Z[i] := \text{LCP}(s, s[i:])$ で定義される配列 $Z$ を求める

$O(n)$ 時間
