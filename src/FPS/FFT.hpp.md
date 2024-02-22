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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/FFT.hpp\"\n// {998244353, 3}, {754974721, 11}, {167772161,\
    \ 3}, {469762049, 3}, {2130706433, 3}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid\
    \ fft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static auto z = []\
    \ {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32) {\n       \
    \  z[i - 2] = s * g.pow(mod >> i);\n         s *= g.inv().pow(mod >> i);\n   \
    \   }\n      return z;\n   }();\n   rep(l, 0, lg) {\n      ll w = 1 << (lg - l\
    \ - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg\
    \ - l);\n         rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w] *\
    \ s;\n            a[i] = x + y;\n            a[i + w] = x - y;\n         }\n \
    \        s *= z[__builtin_ctzll(~k)];\n      }\n   }\n}\n// \u30B3\u30D4\u30DA\
    \nvoid ifft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static auto z\
    \ = [] {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32) {  //\
    \ g \u3092\u9006\u6570\u306B\n         z[i - 2] = s * g.inv().pow(mod >> i);\n\
    \         s *= g.pow(mod >> i);\n      }\n      return z;\n   }();\n   for(ll\
    \ l = lg; l--;) {  // \u9006\u9806\u306B\n      ll w = 1 << (lg - l - 1);\n  \
    \    mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg - l);\n  \
    \       rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w];  // *s \u3092\
    \u79FB\u52D5\n            a[i] = x + y;\n            a[i + w] = (x - y) * s;\n\
    \         }\n         s *= z[__builtin_ctzll(~k)];\n      }\n   }\n}\nvector<mm>\
    \ conv(vector<mm> a, vector<mm> b) {\n   if(a.empty() || b.empty()) return {};\n\
    \   size_t n_ = sz(a) + sz(b) - 1, n = bit_ceil(n_);\n   // if(min(sz(a), sz(b))\
    \ <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n\
    \   fft(a);\n   fft(b);\n   mm x = mm(n).inv();\n   rep(i, 0, n) a[i] *= b[i]\
    \ * x;\n   ifft(a);\n   a.resize(n_);\n   return a;\n}\n"
  code: "// {998244353, 3}, {754974721, 11}, {167772161, 3}, {469762049, 3}, {2130706433,\
    \ 3}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid fft(vector<mm>& a) {\n   ll n = sz(a),\
    \ lg = __lg(n);\n   static auto z = [] {\n      vector<mm> z(30);\n      mm s\
    \ = 1;\n      rep(i, 2, 32) {\n         z[i - 2] = s * g.pow(mod >> i);\n    \
    \     s *= g.inv().pow(mod >> i);\n      }\n      return z;\n   }();\n   rep(l,\
    \ 0, lg) {\n      ll w = 1 << (lg - l - 1);\n      mm s = 1;\n      rep(k, 0,\
    \ 1 << l) {\n         ll o = k << (lg - l);\n         rep(i, o, o + w) {\n   \
    \         mm x = a[i], y = a[i + w] * s;\n            a[i] = x + y;\n        \
    \    a[i + w] = x - y;\n         }\n         s *= z[__builtin_ctzll(~k)];\n  \
    \    }\n   }\n}\n// \u30B3\u30D4\u30DA\nvoid ifft(vector<mm>& a) {\n   ll n =\
    \ sz(a), lg = __lg(n);\n   static auto z = [] {\n      vector<mm> z(30);\n   \
    \   mm s = 1;\n      rep(i, 2, 32) {  // g \u3092\u9006\u6570\u306B\n        \
    \ z[i - 2] = s * g.inv().pow(mod >> i);\n         s *= g.pow(mod >> i);\n    \
    \  }\n      return z;\n   }();\n   for(ll l = lg; l--;) {  // \u9006\u9806\u306B\
    \n      ll w = 1 << (lg - l - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n\
    \         ll o = k << (lg - l);\n         rep(i, o, o + w) {\n            mm x\
    \ = a[i], y = a[i + w];  // *s \u3092\u79FB\u52D5\n            a[i] = x + y;\n\
    \            a[i + w] = (x - y) * s;\n         }\n         s *= z[__builtin_ctzll(~k)];\n\
    \      }\n   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty()\
    \ || b.empty()) return {};\n   size_t n_ = sz(a) + sz(b) - 1, n = bit_ceil(n_);\n\
    \   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n\
    \   b.resize(n);\n   fft(a);\n   fft(b);\n   mm x = mm(n).inv();\n   rep(i, 0,\
    \ n) a[i] *= b[i] * x;\n   ifft(a);\n   a.resize(n_);\n   return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/FFT.hpp
  requiredBy: []
  timestamp: '2024-02-23 07:40:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/FFT.test.cpp
  - test/FPS/FFT_fast.test.cpp
documentation_of: src/FPS/FFT.hpp
layout: document
title: FFT
---

- 参考実装: [AC Library (初期実装)](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/convolution.hpp)

### 注意

- 入力は長さが 2 べきであること
- FFT 後の配列は bit reversal 順に並ぶ

### ベンチマーク

| $2^{20} + 2^{20}$ の畳み込み | 時間 |
| --- | --- |
| [簡易 modint を使う](../modint/modint.hpp) | 246 ms |
| [ちゃんとした modint を使う](../extra/modint_fast.hpp) | 114 ms |
| [AC Library](https://github.com/atcoder/ac-library/blob/d8ca7f26686f6c78d15d13ca438ea866526e87fb/atcoder/convolution.hpp) | 97 ms |
