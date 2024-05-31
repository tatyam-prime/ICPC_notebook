---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/BinaryGCD.test.cpp
    title: test/math/BinaryGCD.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/BinaryGCD.hpp\"\nu64 ctz(u64 x) { return countr_zero(x);\
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
  path: src/math/BinaryGCD.hpp
  requiredBy: []
  timestamp: '2024-06-01 01:21:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/BinaryGCD.test.cpp
documentation_of: src/math/BinaryGCD.hpp
layout: document
title: Binary GCD
---

割り算を使わない高速な GCD

## 使い方

- `u64 binary_gcd(u64 x, u64 y)`：$x$ と $y$ の最大公約数を計算する．
    - $O(\log(x + y))$ 時間
