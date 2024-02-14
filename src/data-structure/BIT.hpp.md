---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/BIT.test.cpp
    title: test/data-structure/BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/data-structure/BIT.hpp\"\nstruct BIT {\n   vector<ll>\
    \ a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll p, ll x) {  // A[p] += x\n  \
    \    p++;\n      while (p < sz(a)) {\n         a[p] += x;\n         p += p & -p;\n\
    \      }\n   }\n   ll sum(ll r) {\n      ll s = 0;\n      while (r > 0) {\n  \
    \       s += a[r];\n         r -= r & -r;\n      }\n      return s;\n   }\n  \
    \ ll sum(ll l, ll r) {  // sum of A[l, r)\n      return sum(r) - sum(l);\n   }\n\
    };\n"
  code: "struct BIT {\n   vector<ll> a;\n   BIT(ll n) : a(n + 1) {}\n   void add(ll\
    \ p, ll x) {  // A[p] += x\n      p++;\n      while (p < sz(a)) {\n         a[p]\
    \ += x;\n         p += p & -p;\n      }\n   }\n   ll sum(ll r) {\n      ll s =\
    \ 0;\n      while (r > 0) {\n         s += a[r];\n         r -= r & -r;\n    \
    \  }\n      return s;\n   }\n   ll sum(ll l, ll r) {  // sum of A[l, r)\n    \
    \  return sum(r) - sum(l);\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2024-02-14 23:41:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/BIT.test.cpp
documentation_of: src/data-structure/BIT.hpp
layout: document
redirect_from:
- /library/src/data-structure/BIT.hpp
- /library/src/data-structure/BIT.hpp.html
title: src/data-structure/BIT.hpp
---
