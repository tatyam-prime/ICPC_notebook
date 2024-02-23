---
title: FFT (高速フーリエ変換 / 畳み込み)
documentation_of: //src/FPS/FFT.hpp
---
- 参考実装：[AC Library (初期実装)](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/convolution.hpp)

## Depends on

- [Modint](../modint/modint.hpp)

## 使い方

- `void fft(vector<mm>& a)`：長さが $2$ べきの数列 $a$ の離散フーリエ変換を行う
- `void ifft(vector<mm>& a)`：長さが $2$ べきの数列 $a$ の逆離散フーリエ変換を行う
- `vector<mm> conv(vector<mm> a, vector<mm> b)`：数列 $a, b$ の畳み込みを行う

$O(n \log n)$ 時間

## 注意

- `fft()`, `ifft()` の入力は長さが 2 べきであること
- FFT 後の配列は bit reversal 順に並ぶ
- FFT → IFFT をすると各要素が $n$ 倍されるので、$n$ で割る必要がある

## ベンチマーク

| $2^{20} + 2^{20}$ の畳み込み | 所要時間 |
| --- | --- |
| [簡易 modint を使う](../modint/modint.hpp) | 244 ms |
| [ちゃんとした modint を使う](../extra/modint_fast.hpp) | 123 ms |
| [AC Library](https://github.com/atcoder/ac-library/blob/d8ca7f26686f6c78d15d13ca438ea866526e87fb/atcoder/convolution.hpp) | 79 ms |
| [Nyaan AVX2](https://nyaannyaan.github.io/library/verify/verify-yosupo-ntt/yosupo-convolution-ntt-avx2.test.cpp) | 43 ms |
