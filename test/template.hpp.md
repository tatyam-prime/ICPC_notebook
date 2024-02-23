---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/FFT.test.cpp
    title: test/FPS/FFT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/FPS/FFT_fast.test.cpp
    title: test/FPS/FFT_fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data-structure/BIT.test.cpp
    title: test/data-structure/BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint/BarrettReduction.test.cpp
    title: test/modint/BarrettReduction.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint/modint.test.cpp
    title: test/modint/modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a,\
    \ b) for(ll i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\nll sz(const\
    \ auto& a) { return size(a); }\nbool chmin(auto& a, auto b) {\n   if(a <= b) return\
    \ 0;\n   a = b;\n   return 1;\n}\nbool chmax(auto& a, auto b) {\n   if(a >= b)\
    \ return 0;\n   a = b;\n   return 1;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll i = a; i < (b); i++)\n\
    #define all(a) begin(a), end(a)\nll sz(const auto& a) { return size(a); }\nbool\
    \ chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n   a = b;\n   return 1;\n\
    }\nbool chmax(auto& a, auto b) {\n   if(a >= b) return 0;\n   a = b;\n   return\
    \ 1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: test/template.hpp
  requiredBy: []
  timestamp: '2024-02-23 13:57:10+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/BIT.test.cpp
  - test/FPS/FFT.test.cpp
  - test/FPS/FFT_fast.test.cpp
  - test/modint/modint.test.cpp
  - test/modint/BarrettReduction.test.cpp
documentation_of: test/template.hpp
layout: document
redirect_from:
- /library/test/template.hpp
- /library/test/template.hpp.html
title: test/template.hpp
---
