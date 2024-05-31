---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/FFT_fast.test.cpp
    title: test/FPS/FFT_fast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/extra/modint_fast.hpp\"\nconst uint32_t mod = 998244353;\n\
    struct mm {\n   uint32_t x;\n   mm() : x(0) {}\n   template<class T> mm(T x_)\
    \ : x(x_ % mod) {\n      if(x >= mod) x += mod;\n   }\n   friend mm operator+(mm\
    \ a, mm b) {\n      a.x += b.x;\n      if(a.x >= mod) a.x -= mod;\n      return\
    \ a;\n   }\n   friend mm operator-(mm a, mm b) {\n      a.x -= b.x;\n      if(a.x\
    \ >= mod) a.x += mod;\n      return a;\n   }\n   friend mm operator*(mm a, mm\
    \ b) { return (uint64_t)a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return\
    \ a * b.inv(); }\n   friend mm& operator+=(mm& a, mm b) { return a = a + b; }\n\
    \   friend mm& operator-=(mm& a, mm b) { return a = a - b; }\n   friend mm& operator*=(mm&\
    \ a, mm b) { return a = a * b; }\n   friend mm& operator/=(mm& a, mm b) { return\
    \ a = a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll\
    \ b) const {\n      mm a = *this, c = 1;\n      while(b) {\n         if(b & 1)\
    \ c *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n\
    };\n"
  code: "const uint32_t mod = 998244353;\nstruct mm {\n   uint32_t x;\n   mm() : x(0)\
    \ {}\n   template<class T> mm(T x_) : x(x_ % mod) {\n      if(x >= mod) x += mod;\n\
    \   }\n   friend mm operator+(mm a, mm b) {\n      a.x += b.x;\n      if(a.x >=\
    \ mod) a.x -= mod;\n      return a;\n   }\n   friend mm operator-(mm a, mm b)\
    \ {\n      a.x -= b.x;\n      if(a.x >= mod) a.x += mod;\n      return a;\n  \
    \ }\n   friend mm operator*(mm a, mm b) { return (uint64_t)a.x * b.x; }\n   friend\
    \ mm operator/(mm a, mm b) { return a * b.inv(); }\n   friend mm& operator+=(mm&\
    \ a, mm b) { return a = a + b; }\n   friend mm& operator-=(mm& a, mm b) { return\
    \ a = a - b; }\n   friend mm& operator*=(mm& a, mm b) { return a = a * b; }\n\
    \   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n   mm inv()\
    \ const { return pow(mod - 2); }\n   mm pow(ll b) const {\n      mm a = *this,\
    \ c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n         a *= a;\n   \
    \      b >>= 1;\n      }\n      return c;\n   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/extra/modint_fast.hpp
  requiredBy: []
  timestamp: '2024-04-04 07:37:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/FFT_fast.test.cpp
documentation_of: src/extra/modint_fast.hpp
layout: document
title: "32 bit \u3067\u52A0\u6E1B\u7B97\u3092\u3061\u3083\u3093\u3068\u66F8\u3044\u305F\
  \ Modint"
---

modint の速度が欲しいときに使う  
PDF には含まれていません


