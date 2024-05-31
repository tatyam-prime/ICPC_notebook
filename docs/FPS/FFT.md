---
title: FFT (高速フーリエ変換 / 畳み込み)
documentation_of: //src/FPS/FFT.hpp
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
