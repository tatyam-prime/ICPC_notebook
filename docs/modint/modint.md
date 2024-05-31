---
title: Modint
documentation_of: //src/modint/modint.hpp
---
- 参考実装：[AC Library (初期実装)](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/convolution.hpp)

- タイプ速度重視の簡易 modint
- 速度が欲しいとき：[32 bit で加減算をちゃんと書いた Modint](../extra/modint_fast.hpp)
- mod が素数でないとき：inv を [extgcd](../math/ExtGCD.hpp) にする
- mod が実行時に決まり，これを高速化したいとき：[Barrett Reduction](./BarrettReduction.hpp)
