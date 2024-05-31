---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/FFT.test.cpp
    title: test/FPS/FFT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint/modint.test.cpp
    title: test/modint/modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/modint/modint.hpp\"\nconst ll mod = 998244353;\nstruct\
    \ mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n\
    \   }\n   friend mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend mm\
    \ operator-(mm a, mm b) { return a.x - b.x; }\n   friend mm operator*(mm a, mm\
    \ b) { return a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return a * b.inv();\
    \ }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\
    \u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm& a, mm b) {\
    \ return a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) { return a =\
    \ a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x;\
    \ }\n   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n   mm\
    \ inv() const { return pow(mod - 2); }\n   mm pow(ll b) const {\n      mm a =\
    \ *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n         a *= a;\n\
    \         b >>= 1;\n      }\n      return c;\n   }\n};\n"
  code: "const ll mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_\
    \ % mod) {\n      if(x < 0) x += mod;\n   }\n   friend mm operator+(mm a, mm b)\
    \ { return a.x + b.x; }\n   friend mm operator-(mm a, mm b) { return a.x - b.x;\
    \ }\n   friend mm operator*(mm a, mm b) { return a.x * b.x; }\n   friend mm operator/(mm\
    \ a, mm b) { return a * b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift\
    \ + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend\
    \ mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm&\
    \ a, mm b) { return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) {\
    \ return a = a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a =\
    \ a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b)\
    \ const {\n      mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c\
    \ *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/modint/modint.hpp
  requiredBy: []
  timestamp: '2024-02-23 02:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/FFT.test.cpp
  - test/modint/modint.test.cpp
documentation_of: src/modint/modint.hpp
layout: document
title: Modint
---

- タイプ速度重視の簡易 modint
- 速度が欲しいとき：[32 bit で加減算をちゃんと書いた Modint](../extra/modint_fast.hpp)
- mod が素数でないとき：inv を extgcd にする
- mod が実行時に決まり，これを高速化したいとき：[Barrett Reduction](./BarrettReduction.hpp)
