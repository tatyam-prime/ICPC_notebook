---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/FastGCD.test.cpp
    title: test/math/FastGCD.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/FastGCD.hpp\"\nu64 ctz(u64 x) { return countr_zero(x);\
    \ }\nu64 binary_gcd(u64 x, u64 y) {\n   if(!x || !y) return x | y;\n   u64 n =\
    \ ctz(x), m = ctz(y);\n   x >>= n, y >>= m;\n   while(x != y) {\n      if(x >\
    \ y) x = (x - y) >> ctz(x - y);\n      else y = (y - x) >> ctz(y - x);\n   }\n\
    \   return x << min(n, m);\n}\n"
  code: "u64 ctz(u64 x) { return countr_zero(x); }\nu64 binary_gcd(u64 x, u64 y) {\n\
    \   if(!x || !y) return x | y;\n   u64 n = ctz(x), m = ctz(y);\n   x >>= n, y\
    \ >>= m;\n   while(x != y) {\n      if(x > y) x = (x - y) >> ctz(x - y);\n   \
    \   else y = (y - x) >> ctz(y - x);\n   }\n   return x << min(n, m);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/FastGCD.hpp
  requiredBy: []
  timestamp: '2024-05-31 23:58:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/FastGCD.test.cpp
documentation_of: src/math/FastGCD.hpp
layout: document
redirect_from:
- /library/src/math/FastGCD.hpp
- /library/src/math/FastGCD.hpp.html
title: src/math/FastGCD.hpp
---
