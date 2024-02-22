---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FPS/FFT.test.cpp
    title: test/FPS/FFT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/FFT.hpp\"\n// {998244353, 3}, {2013265921, 31},\
    \ {2113929217, 5}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid fft(vector<mm>& a) {\n\
    \   ll n = sz(a), lg = __lg(n);\n   static auto z = [] {\n      vector<mm> z(30);\n\
    \      mm s = 1;\n      rep(i, 2, 32) {\n         z[i - 2] = s * g.pow((mod -\
    \ 1) >> i);\n         s *= g.inv().pow((mod - 1) >> i);\n      }\n      return\
    \ z;\n   }();\n   rep(l, 0, lg) {\n      ll w = 1 << (lg - l - 1);\n      mm s\
    \ = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg - l);\n         rep(i,\
    \ o, o + w) {\n            mm x = a[i], y = a[i + w] * s;\n            a[i] =\
    \ x + y;\n            a[i + w] = x - y;\n         }\n         s *= z[__builtin_ctzll(~k)];\n\
    \      }\n   }\n}\n// \u30B3\u30D4\u30DA\nvoid ifft(vector<mm>& a) {\n   ll n\
    \ = sz(a), lg = __lg(n);\n   static auto z = [] {\n      vector<mm> z(30);\n \
    \     mm s = 1;\n      rep(i, 2, 32) {  // g \u3092\u9006\u6570\u306B\n      \
    \   z[i - 2] = s * g.inv().pow((mod - 1) >> i);\n         s *= g.pow((mod - 1)\
    \ >> i);\n      }\n      return z;\n   }();\n   for(ll l = lg; l--;) {  // \u9006\
    \u9806\u306B\n      ll w = 1 << (lg - l - 1);\n      mm s = 1;\n      rep(k, 0,\
    \ 1 << l) {\n         ll o = k << (lg - l);\n         rep(i, o, o + w) {\n   \
    \         mm x = a[i], y = a[i + w];  // *s \u3092\u79FB\u52D5\n            a[i]\
    \ = x + y;\n            a[i + w] = (x - y) * s;\n         }\n         s *= z[__builtin_ctzll(~k)];\n\
    \      }\n   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty()\
    \ || b.empty()) return {};\n   size_t n_ = sz(a) + sz(b) - 1, n = bit_ceil(n_);\n\
    \   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n\
    \   b.resize(n);\n   fft(a);\n   fft(b);\n   mm x = mm(n).inv();\n   rep(i, 0,\
    \ n) a[i] *= b[i] * x;\n   ifft(a);\n   a.resize(n_);\n   return a;\n}\n"
  code: "// {998244353, 3}, {2013265921, 31}, {2113929217, 5}\nmm g = 3;  // \u539F\
    \u59CB\u6839\nvoid fft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static\
    \ auto z = [] {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32)\
    \ {\n         z[i - 2] = s * g.pow((mod - 1) >> i);\n         s *= g.inv().pow((mod\
    \ - 1) >> i);\n      }\n      return z;\n   }();\n   rep(l, 0, lg) {\n      ll\
    \ w = 1 << (lg - l - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n       \
    \  ll o = k << (lg - l);\n         rep(i, o, o + w) {\n            mm x = a[i],\
    \ y = a[i + w] * s;\n            a[i] = x + y;\n            a[i + w] = x - y;\n\
    \         }\n         s *= z[__builtin_ctzll(~k)];\n      }\n   }\n}\n// \u30B3\
    \u30D4\u30DA\nvoid ifft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static\
    \ auto z = [] {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32)\
    \ {  // g \u3092\u9006\u6570\u306B\n         z[i - 2] = s * g.inv().pow((mod -\
    \ 1) >> i);\n         s *= g.pow((mod - 1) >> i);\n      }\n      return z;\n\
    \   }();\n   for(ll l = lg; l--;) {  // \u9006\u9806\u306B\n      ll w = 1 <<\
    \ (lg - l - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k\
    \ << (lg - l);\n         rep(i, o, o + w) {\n            mm x = a[i], y = a[i\
    \ + w];  // *s \u3092\u79FB\u52D5\n            a[i] = x + y;\n            a[i\
    \ + w] = (x - y) * s;\n         }\n         s *= z[__builtin_ctzll(~k)];\n   \
    \   }\n   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty()\
    \ || b.empty()) return {};\n   size_t n_ = sz(a) + sz(b) - 1, n = bit_ceil(n_);\n\
    \   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n\
    \   b.resize(n);\n   fft(a);\n   fft(b);\n   mm x = mm(n).inv();\n   rep(i, 0,\
    \ n) a[i] *= b[i] * x;\n   ifft(a);\n   a.resize(n_);\n   return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/FFT.hpp
  requiredBy: []
  timestamp: '2024-02-23 02:52:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/FFT.test.cpp
documentation_of: src/FPS/FFT.hpp
layout: document
redirect_from:
- /library/src/FPS/FFT.hpp
- /library/src/FPS/FFT.hpp.html
title: src/FPS/FFT.hpp
---
