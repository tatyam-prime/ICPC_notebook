---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/KMP.test.cpp
    title: test/string/KMP.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/KMP.hpp\"\n// kmp[i] := max{ l \u2264 i | s[:l]\
    \ == s[(i+1)-l:i+1] }\n// abacaba -> 0010123\nauto KMP(string s) {\n   vector<ll>\
    \ p(sz(s));\n   rep(i, 1, sz(s)) {\n      ll g = p[i - 1];\n      while(g && s[i]\
    \ != s[g]) g = p[g - 1];\n      p[i] = g + (s[i] == s[g]);\n   }\n   return p;\n\
    }\n"
  code: "// kmp[i] := max{ l \u2264 i | s[:l] == s[(i+1)-l:i+1] }\n// abacaba -> 0010123\n\
    auto KMP(string s) {\n   vector<ll> p(sz(s));\n   rep(i, 1, sz(s)) {\n      ll\
    \ g = p[i - 1];\n      while(g && s[i] != s[g]) g = p[g - 1];\n      p[i] = g\
    \ + (s[i] == s[g]);\n   }\n   return p;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/KMP.hpp
  requiredBy: []
  timestamp: '2024-05-31 19:01:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/KMP.test.cpp
documentation_of: src/string/KMP.hpp
layout: document
title: "KMP \u6CD5 (Knuth\u2013Morris\u2013Pratt algorithm)"
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/c52bac765cdd9cda1def052c698ffa7bd3318d29/content/strings/KMP.h)

## 使い方

- `vector<ll> KMP(string s)`：$\text{kmp}[i] := \max\\{ l ≤ i \mid s[:l] = s[(i+1)-l:i+1] \\}$ で定義される配列 $\text{kmp}$ を求める

$O(n)$ 時間
