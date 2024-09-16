---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/ExtGCD.test.cpp
    title: test/math/ExtGCD.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/ExtGCD.hpp\"\n// returns gcd(a, b) and assign x,\
    \ y to integers\n// s.t. ax + by = gcd(a, b) and |x| + |y| is minimized\nll extgcd(ll\
    \ a, ll b, ll& x, ll& y) {\n   // assert(a >= 0 && b >= 0);\n   if(!b) return\
    \ x = 1, y = 0, a;\n   ll d = extgcd(b, a % b, y, x);\n   y -= a / b * x;\n  \
    \ return d;\n}\n"
  code: "// returns gcd(a, b) and assign x, y to integers\n// s.t. ax + by = gcd(a,\
    \ b) and |x| + |y| is minimized\nll extgcd(ll a, ll b, ll& x, ll& y) {\n   //\
    \ assert(a >= 0 && b >= 0);\n   if(!b) return x = 1, y = 0, a;\n   ll d = extgcd(b,\
    \ a % b, y, x);\n   y -= a / b * x;\n   return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/ExtGCD.hpp
  requiredBy: []
  timestamp: '2024-06-01 02:08:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/ExtGCD.test.cpp
documentation_of: src/math/ExtGCD.hpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5 (Extended\
  \ Euclidean algorithm)"
---
- 参考実装：[KACTL](https://github.com/kth-competitive-programming/kactl/blob/main/content/number-theory/euclid.h)

## 使い方

- `ll extgcd(ll a, ll b, ll& x, ll& y)`：$\text{gcd}(a, b)$ を返す．$(x, y)$ には，$ax + by = \text{gcd}(a, b)$ の整数解であって $\|x\| + \|y\|$ が最小のものが代入される．
    - $O(\log(x + y))$ 時間

## 使い方 (応用)

- モジュロ逆元 `modinv(a, mod)` を求める：`extgcd(a, mod, x, y)` をすると `a * x + mod * y == 1` になるので，`x` が `a` のモジュロ逆元である．

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

