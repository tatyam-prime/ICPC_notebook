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
  bundledCode: "#line 1 \"src/FPS/FFT_fast.hpp\"\n// modint \u3092 u32 \u306B\u3057\
    \u3066\u52A0\u6E1B\u7B97\u3092\u771F\u9762\u76EE\u306B\u3084\u308B\u3068\u901F\
    \u3044\nmm g = 3;  // \u539F\u59CB\u6839\nvoid fft(vector<mm>& a) {\n   ll n =\
    \ sz(a), lg = __lg(n);\n   static auto z = [] {\n      vector<mm> z(30);\n   \
    \   mm s = 1;\n      rep(i, 2, 32) {\n         z[i - 2] = s * g.pow(mod >> i);\n\
    \         s *= g.inv().pow(mod >> i);\n      }\n      return z;\n   }();\n   rep(l,\
    \ 0, lg) {\n      ll w = 1 << (lg - l - 1);\n      mm s = 1;\n      rep(k, 0,\
    \ 1 << l) {\n         ll o = k << (lg - l);\n         rep(i, o, o + w) {\n   \
    \         mm x = a[i], y = a[i + w] * s;\n            a[i] = x + y;\n        \
    \    a[i + w] = x - y;\n         }\n         s *= z[countr_zero<uint64_t>(~k)];\n\
    \      }\n   }\n}\n// \u30B3\u30D4\u30DA\nvoid ifft(vector<mm>& a) {\n   ll n\
    \ = sz(a), lg = __lg(n);\n   static auto z = [] {\n      vector<mm> z(30);\n \
    \     mm s = 1;\n      rep(i, 2, 32) {  // g \u3092\u9006\u6570\u306B\n      \
    \   z[i - 2] = s * g.inv().pow(mod >> i);\n         s *= g.pow(mod >> i);\n  \
    \    }\n      return z;\n   }();\n   for(ll l = lg; l--;) {  // \u9006\u9806\u306B\
    \n      ll w = 1 << (lg - l - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n\
    \         ll o = k << (lg - l);\n         rep(i, o, o + w) {\n            mm x\
    \ = a[i], y = a[i + w];  // *s \u3092\u4E0B\u306B\u79FB\u52D5\n            a[i]\
    \ = x + y;\n            a[i + w] = (x - y) * s;\n         }\n         s *= z[countr_zero<uint64_t>(~k)];\n\
    \      }\n   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty()\
    \ || b.empty()) return {};\n   size_t s = sz(a) + sz(b) - 1, n = bit_ceil(s);\n\
    \   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n\
    \   b.resize(n);\n   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   rep(i,\
    \ 0, n) a[i] *= b[i] * inv;\n   ifft(a);\n   a.resize(s);\n   return a;\n}\n"
  code: "// modint \u3092 u32 \u306B\u3057\u3066\u52A0\u6E1B\u7B97\u3092\u771F\u9762\
    \u76EE\u306B\u3084\u308B\u3068\u901F\u3044\nmm g = 3;  // \u539F\u59CB\u6839\n\
    void fft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static auto z =\
    \ [] {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32) {\n    \
    \     z[i - 2] = s * g.pow(mod >> i);\n         s *= g.inv().pow(mod >> i);\n\
    \      }\n      return z;\n   }();\n   rep(l, 0, lg) {\n      ll w = 1 << (lg\
    \ - l - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k <<\
    \ (lg - l);\n         rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w]\
    \ * s;\n            a[i] = x + y;\n            a[i + w] = x - y;\n         }\n\
    \         s *= z[countr_zero<uint64_t>(~k)];\n      }\n   }\n}\n// \u30B3\u30D4\
    \u30DA\nvoid ifft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static\
    \ auto z = [] {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32)\
    \ {  // g \u3092\u9006\u6570\u306B\n         z[i - 2] = s * g.inv().pow(mod >>\
    \ i);\n         s *= g.pow(mod >> i);\n      }\n      return z;\n   }();\n   for(ll\
    \ l = lg; l--;) {  // \u9006\u9806\u306B\n      ll w = 1 << (lg - l - 1);\n  \
    \    mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg - l);\n  \
    \       rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w];  // *s \u3092\
    \u4E0B\u306B\u79FB\u52D5\n            a[i] = x + y;\n            a[i + w] = (x\
    \ - y) * s;\n         }\n         s *= z[countr_zero<uint64_t>(~k)];\n      }\n\
    \   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty() || b.empty())\
    \ return {};\n   size_t s = sz(a) + sz(b) - 1, n = bit_ceil(s);\n   // if(min(sz(a),\
    \ sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n\
    \   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   rep(i, 0, n) a[i] *= b[i]\
    \ * inv;\n   ifft(a);\n   a.resize(s);\n   return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/FFT_fast.hpp
  requiredBy: []
  timestamp: '2024-04-06 01:55:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FPS/FFT_fast.test.cpp
documentation_of: src/FPS/FFT_fast.hpp
layout: document
title: FFT (bit reversal ver.)
---
- 参考実装：[AC Library (初期実装)](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/convolution.hpp)

## Depends on

- [Modint](../modint/modint.hpp)

より高速な FFT．4 進でやるとより高速になるが，長すぎるので妥協

## 使い方

- `void fft(vector<mm>& a)`：長さが $n$ : $2$ べきの数列 $a$ の離散フーリエ変換を行う
    - **`fft()` 後の配列は bit reversal 順になっていることに注意．**例えば $n = 16$ のとき，$(0101)_2 = 5$ の bit 順を反転させると $(1010)_2 = 10$ であるから，$f(\omega^5)$ の値は $a[10]$ に入っている．
- `void ifft(vector<mm>& a)`：`fft()` の逆変換を行う
- `vector<mm> conv(vector<mm> a, vector<mm> b)`：数列 $a, b$ の畳み込みを行う
    - $c[k] := \sum_{i + j = k}a[i] \times b[j]$ で定義される，長さ $\text{sz}(a) + \text{sz}(b) - 1$ の数列 $c$ を返す．

$O(n \log n)$ 時間

## 注意

- `fft()`, `ifft()` の入力は長さが 2 べきであること
- FFT 後の配列は bit reversal 順に並ぶ
- FFT → IFFT をすると各要素が $n$ 倍されるので、$n$ で割る必要がある
