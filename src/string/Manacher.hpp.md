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
  bundledCode: "#line 1 \"src/string/Manacher.hpp\"\n// \u5404\u4F4D\u7F6E\u3067\u306E\
    \u56DE\u6587\u534A\u5F84\u3092\u6C42\u3081\u308B\n// aaabaaa -> 1214121\n// \u5076\
    \u6570\u9577\u306E\u56DE\u6587\u3092\u542B\u3081\u3066\u76F4\u5F84\u3092\u77E5\
    \u308B\u306B\u306F\uFF0CN+1 \u500B\u306E $ \u3092\u633F\u5165\u3057\u3066 1 \u3092\
    \u5F15\u304F\n// $a$a$a$b$a$a$a$ -> 123432181234321\nauto manacher(string s) {\n\
    \   ll n = sz(s), i = 0, j = 0;\n   vector<ll> r(n);\n   while(i < n) {\n    \
    \  while(i >= j && i + j < n && s[i - j] == s[i + j]) j++;\n      r[i] = j;\n\
    \      ll k = 1;\n      while(i >= k && i + k < n && k + r[i - k] < j) {\n   \
    \      r[i + k] = r[i - k];\n         k++;\n      }\n      i += k, j -= k;\n \
    \  }\n   return r;\n}\n"
  code: "// \u5404\u4F4D\u7F6E\u3067\u306E\u56DE\u6587\u534A\u5F84\u3092\u6C42\u3081\
    \u308B\n// aaabaaa -> 1214121\n// \u5076\u6570\u9577\u306E\u56DE\u6587\u3092\u542B\
    \u3081\u3066\u76F4\u5F84\u3092\u77E5\u308B\u306B\u306F\uFF0CN+1 \u500B\u306E $\
    \ \u3092\u633F\u5165\u3057\u3066 1 \u3092\u5F15\u304F\n// $a$a$a$b$a$a$a$ -> 123432181234321\n\
    auto manacher(string s) {\n   ll n = sz(s), i = 0, j = 0;\n   vector<ll> r(n);\n\
    \   while(i < n) {\n      while(i >= j && i + j < n && s[i - j] == s[i + j]) j++;\n\
    \      r[i] = j;\n      ll k = 1;\n      while(i >= k && i + k < n && k + r[i\
    \ - k] < j) {\n         r[i + k] = r[i - k];\n         k++;\n      }\n      i\
    \ += k, j -= k;\n   }\n   return r;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Manacher.hpp
  requiredBy: []
  timestamp: '2024-05-31 19:01:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/Manacher.test.cpp
documentation_of: src/string/Manacher.hpp
layout: document
title: Manacher's algorithm
---
- 参考実装：[ei1333 (Luzhiled's memo)](https://ei1333.github.io/luzhiled/snippets/string/manacher.html)

## 使い方

- `vector<ll> manacher(string s)`：文字列 $s$ の長さを $n$ として，長さ $n$ の整数列 $r$ を返す．$r[i]$ は $s[i]$ を中心とする回文半径で，$s[i - r[i]]$ から $s[i + r[i]]$ までが回文であることを表す．
- 文字と文字の間を中心とする回文半径も知りたいときは，両端を含めた境界 ($N + 1$ 個) に適当な文字 1 種類を挿入しておく．返される値は，挿入前の文字列における回文直径${} + 1$ (すなわち，極大な回文の長さ${} + 1$) になる．

$O(n)$ 時間
