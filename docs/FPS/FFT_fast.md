---
title: FFT (bit reversal ver.)
documentation_of: //src/FPS/FFT_fast.hpp
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
