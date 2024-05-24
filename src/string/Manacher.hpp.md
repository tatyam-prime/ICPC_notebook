---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/Manacher.test.cpp
    title: test/string/Manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/Manacher.hpp\"\n// returns array {even-length,\
    \ odd-length} palindromes\n// aaabaaa -> {01100110, 0103010}\n// even-length \u306F\
    \u9577\u3055 n+1 : \u4E21\u7AEF\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u3082\u306E\
    \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u3053\u3068\u306B\u6CE8\u610F\nauto\
    \ manacher(string s) {\n   ll n = sz(s);\n   array p = {vector<ll>(n + 1), vector<ll>(n)};\n\
    \   rep(z, 0, 2) for(ll i = 0, l = 0, r = 0; i < n; i++) {\n      ll t = r - i\
    \ + !z;\n      if(i < r) p[z][i] = min(t, p[z][l + t]);\n      ll L = i - p[z][i],\
    \ R = i + p[z][i] - !z;\n      while(L >= 1 && R + 1 < n && s[L - 1] == s[R +\
    \ 1]) {\n         p[z][i]++;\n         L--;\n         R++;\n      }\n      if(R\
    \ > r) {\n         l = L;\n         r = R;\n      }\n   }\n   return p;\n}\n"
  code: "// returns array {even-length, odd-length} palindromes\n// aaabaaa -> {01100110,\
    \ 0103010}\n// even-length \u306F\u9577\u3055 n+1 : \u4E21\u7AEF\u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u3082\u306E\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u3053\
    \u3068\u306B\u6CE8\u610F\nauto manacher(string s) {\n   ll n = sz(s);\n   array\
    \ p = {vector<ll>(n + 1), vector<ll>(n)};\n   rep(z, 0, 2) for(ll i = 0, l = 0,\
    \ r = 0; i < n; i++) {\n      ll t = r - i + !z;\n      if(i < r) p[z][i] = min(t,\
    \ p[z][l + t]);\n      ll L = i - p[z][i], R = i + p[z][i] - !z;\n      while(L\
    \ >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) {\n         p[z][i]++;\n        \
    \ L--;\n         R++;\n      }\n      if(R > r) {\n         l = L;\n         r\
    \ = R;\n      }\n   }\n   return p;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Manacher.hpp
  requiredBy: []
  timestamp: '2024-05-24 10:03:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/Manacher.test.cpp
documentation_of: src/string/Manacher.hpp
layout: document
title: Manacher's algorithm
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/Manacher.h)

## 使い方

- `array<vector<ll>, 2> Z(const string& s)`：$Z[i] := \text{LCP}(s, s[i:])$ で定義される配列 $Z$ を求める

$O(n)$ 時間
