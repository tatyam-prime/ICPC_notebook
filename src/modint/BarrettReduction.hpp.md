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
  timestamp: '2024-05-31 19:01:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint/BarrettReduction.test.cpp
documentation_of: src/modint/BarrettReduction.hpp
layout: document
title: Barrett Reduction
---

同じ mod でたくさん計算するとき，剰余算を掛け算に変換して高速化する．

## 使い方

- `Barrett br(mod)`：Barrett Reduction を準備する．
    - 制約：`mod < 2^32`
- `br.mul(u64 a, u64 b)`：`a * b % mod` を計算する．
    - 制約：`a * b < 2^64`

## 仕組み

- 整数部 64 bit，小数部 64 bit の固定小数点数で商を計算する．
- `im` には `1.0 / mod` の小数部 64 bit が書かれている．
- `u64 x = ((__uint128_t)a * im) >> 64;` で商を計算している．

## 余談

ジャッジが Ice Lake より前の Intel の CPU の場合，64 bit 除算が double 除算より 3 倍以上遅いことが知られている．  
あまりではなく商が欲しい場合，mod が固定ではない場合，もっと短くかきたい場合は，double 除算や long double 除算を書くと良い． 
