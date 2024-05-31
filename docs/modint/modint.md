---
title: Modint
documentation_of: //src/modint/modint.hpp
---

- タイプ速度重視の簡易 modint
- 速度が欲しいとき：[32 bit で加減算をちゃんと書いた Modint](../extra/modint_fast.hpp)
- mod が素数でないとき：inv を extgcd にする
- mod が実行時に決まり，これを高速化したいとき：[Barrett Reduction](./BarrettReduction.hpp)
