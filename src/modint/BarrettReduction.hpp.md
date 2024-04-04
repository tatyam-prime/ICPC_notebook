---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/modint/BarrettReduction.test.cpp
    title: test/modint/BarrettReduction.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/modint/BarrettReduction.hpp\"\n// using u64 = uint64_t;\n\
    struct Barrett {  // mod < 2^32\n   u64 m, im;\n   Barrett(u64 mod) : m(mod),\
    \ im(-1ULL / m + 1) {}\n   // input: a * b < 2^64, output: a * b % mod\n   u64\
    \ mul(u64 a, u64 b) const {\n      a *= b;\n      u64 x = ((__uint128_t)a * im)\
    \ >> 64;\n      a -= x * m;\n      if((ll)a < 0) a += m;\n      return a;\n  \
    \ }\n};\n"
  code: "// using u64 = uint64_t;\nstruct Barrett {  // mod < 2^32\n   u64 m, im;\n\
    \   Barrett(u64 mod) : m(mod), im(-1ULL / m + 1) {}\n   // input: a * b < 2^64,\
    \ output: a * b % mod\n   u64 mul(u64 a, u64 b) const {\n      a *= b;\n     \
    \ u64 x = ((__uint128_t)a * im) >> 64;\n      a -= x * m;\n      if((ll)a < 0)\
    \ a += m;\n      return a;\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/BarrettReduction.hpp
  requiredBy: []
  timestamp: '2024-04-04 09:48:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint/BarrettReduction.test.cpp
documentation_of: src/modint/BarrettReduction.hpp
layout: document
redirect_from:
- /library/src/modint/BarrettReduction.hpp
- /library/src/modint/BarrettReduction.hpp.html
title: src/modint/BarrettReduction.hpp
---
