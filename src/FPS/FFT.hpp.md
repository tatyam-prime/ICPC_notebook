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
  bundledCode: "#line 1 \"src/FPS/FFT.hpp\"\n// {998244353, 3}, {1811939329, 13},\
    \ {2013265921, 31}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid fft(vector<mm>& a)\
    \ {\n   ll n = sz(a), lg = __lg(n);\n   assert((1 << lg) == n);\n   vector<mm>\
    \ b(n);\n   rep(l, 1, lg + 1) {\n      ll w = n >> l;\n      mm s = 1, r = g.pow(mod\
    \ >> l);\n      for(ll u = 0; u < n / 2; u += w) {\n         rep(d, 0, w) {\n\
    \            mm x = a[u << 1 | d], y = a[u << 1 | w | d] * s;\n            b[u\
    \ | d] = x + y;\n            b[n >> 1 | u | d] = x - y;\n         }\n        \
    \ s *= r;\n      }\n      swap(a, b);\n   }\n}\nvector<mm> conv(vector<mm> a,\
    \ vector<mm> b) {\n   if(a.empty() || b.empty()) return {};\n   size_t s = sz(a)\
    \ + sz(b) - 1, n = bit_ceil(s);\n   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\
    \u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n   fft(a);\n   fft(b);\n\
    \   mm inv = mm(n).inv();\n   rep(i, 0, n) a[i] *= b[i] * inv;\n   reverse(1 +\
    \ all(a));\n   fft(a);\n   a.resize(s);\n   return a;\n}\n"
  code: "// {998244353, 3}, {1811939329, 13}, {2013265921, 31}\nmm g = 3;  // \u539F\
    \u59CB\u6839\nvoid fft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   assert((1\
    \ << lg) == n);\n   vector<mm> b(n);\n   rep(l, 1, lg + 1) {\n      ll w = n >>\
    \ l;\n      mm s = 1, r = g.pow(mod >> l);\n      for(ll u = 0; u < n / 2; u +=\
    \ w) {\n         rep(d, 0, w) {\n            mm x = a[u << 1 | d], y = a[u <<\
    \ 1 | w | d] * s;\n            b[u | d] = x + y;\n            b[n >> 1 | u | d]\
    \ = x - y;\n         }\n         s *= r;\n      }\n      swap(a, b);\n   }\n}\n\
    vector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty() || b.empty()) return\
    \ {};\n   size_t s = sz(a) + sz(b) - 1, n = bit_ceil(s);\n   // if(min(sz(a),\
    \ sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n\
    \   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   rep(i, 0, n) a[i] *= b[i]\
    \ * inv;\n   reverse(1 + all(a));\n   fft(a);\n   a.resize(s);\n   return a;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/FFT.hpp
  requiredBy: []
  timestamp: '2024-05-31 19:01:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/FFT.test.cpp
documentation_of: src/FPS/FFT.hpp
layout: document
title: "FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB / \u7573\u307F\u8FBC\
  \u307F)"
---
- 参考実装：[gifted infants](https://yosupo.hatenablog.com/entry/2019/07/02/122433)

## Depends on

- [Modint](../modint/modint.hpp)

## 使い方

- `void fft(vector<mm>& a)`：長さが $n$ : $2$ べきの数列 $a$ の離散フーリエ変換を行う．
    - $f(x) := a[0] + a[1]x + \dots + a[n - 1]x^{n - 1},\ \omega := e^{i\frac{\tau}{n}}$ としたとき，列 $[f(\omega^0), f(\omega^1), \dots, f(\omega^{n-1})]$ を返す．
    - **bit reversal 順ではないことに注意**
- `vector<mm> conv(vector<mm> a, vector<mm> b)`：数列 $a, b$ の畳み込みを行う．
    - $c[k] := \sum_{i + j = k}a[i] \times b[j]$ で定義される，長さ $\text{sz}(a) + \text{sz}(b) - 1$ の数列 $c$ を返す．

$O(n \log n)$ 時間

## 注意

- `fft()` の入力は長さが 2 べきであること
- **IFFT は，FFT における $[\omega^1, \dots, \omega^{n-1}]$ を $[\omega^{n-1}, \dots, \omega^{1}]$ で置き換えたものなので，FFT の結果の $[f(\omega^1), \dots, f(\omega^{n-1})]$ の部分を reverse すれば良い．出力を reverse する代わりに，入力の同じ部分を reverse しても良い．**
- FFT → IFFT をすると各要素が $n$ 倍されるので、$n$ で割る必要がある

## ベンチマーク

| $2^{20} + 2^{20}$ の畳み込み | 所要時間 |
| --- | --- |
| [簡易 modint](../modint/modint.hpp) + 簡易 FFT (これ) | 300 ms |
| [32 bit で加減算をちゃんと書いた modint](../extra/modint_fast.hpp) + [bit reversal FFT](FFT_fast.hpp) | 123 ms |
| [AC Library](https://github.com/atcoder/ac-library/blob/d8ca7f26686f6c78d15d13ca438ea866526e87fb/atcoder/convolution.hpp) | 79 ms |
| [Nyaan さんの AVX2 FFT](https://nyaannyaan.github.io/library/verify/verify-yosupo-ntt/yosupo-convolution-ntt-avx2.test.cpp) | 43 ms |
