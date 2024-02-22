---
title: FFT
documentation_of: //src/FPS/FFT.hpp
---

- 参考実装: [AC Library (初期実装)](https://github.com/atcoder/ac-library/blob/8250de484ae0ab597391db58040a602e0dc1a419/atcoder/convolution.hpp)

### 注意

- 入力は長さが 2 べきであること
- FFT 後の配列は bit reversal 順に並ぶ

### ベンチマーク

| $2^{20} + 2^{20}$ の畳み込み | 時間 |
| --- | --- |
| [簡易 modint を使う](../modint/modint.hpp) | 246 ms |
| [ちゃんとした modint を使う](../extra/modint_fast.hpp) | 114 ms |
| [AC Library](https://github.com/atcoder/ac-library/blob/d8ca7f26686f6c78d15d13ca438ea866526e87fb/atcoder/convolution.hpp) | 97 ms |
