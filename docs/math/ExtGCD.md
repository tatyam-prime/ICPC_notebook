---
title: 拡張ユークリッドの互除法 (Extended Euclidean algorithm)
documentation_of: //src/math/ExtGCD.hpp
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/euclid.h)

割り算を使わない高速な GCD

## 使い方

- `ll extgcd(ll a, ll b, ll& x, ll& y)`：$\text{gcd}(a, b)$ を返す．$(x, y)$ には，$ax + by = \text{gcd}(a, b)$ の整数解であって $\|x\| + \|y\|$ が最小のものが代入される．
    - $O(\log(x + y))$ 時間

## ソラ書きしてみよう

$(1, 0, a)$ と $(0, 1, b)$ に対してユークリッドの互除法をするとできる．

```cpp
array<ll, 3> extgcd(ll a, ll b) {
    array<ll, 3> A = {1, 0, a}, B = {0, 1, b};
    while(B[2]) {
        ll q = A[2] / B[2];
        rep(i, 0, 3) A[i] -= B[i] * q;
        swap(A, B);
    }
    return A;
}
```

