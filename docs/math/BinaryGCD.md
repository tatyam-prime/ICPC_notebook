---
title: Binary GCD
documentation_of: //src/math/BinaryGCD.hpp
---

割り算を使わない高速な GCD

## 使い方

- `u64 binary_gcd(u64 x, u64 y)`：$x$ と $y$ の最大公約数を計算する．
    - $O(\log(x + y))$ 時間
