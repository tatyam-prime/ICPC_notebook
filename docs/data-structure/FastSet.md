---
title: 高速 bitset (64 分木)
documentation_of: //src/data-structure/FastSet.hpp
---

- 参考実装：[Gifted Infants](https://yosupo.hatenablog.com/entry/2019/07/02/122433)

## 使い方

整数の set を高速化したい時に使う

- `FastSet(ll n)`：長さ $n$ の bitset を作る
- `void set(ll i)`：`A[i] = true` を行う
- `void reset(ll i)`：`A[i] = false` を行う
- `ll next(ll i)`：$i$ を超える最小の要素を求める
    - std::set における `A.upper_bound(i)` に相当
    - std::bitset における `A._Find_next(i)` に相当
- `ll prev(ll i)`：$i$ より小さい最大の要素を求める
    - std::set における `prev(A.lower_bound(i))` に相当

時間計算量 $O(\log_{\text{word}} n)$ / クエリ  
空間計算量 $(\frac{\text{word}}{\text{word} - 1}\cdot n + O(\log_{\text{word}} n))$ bits　<span style="color:firebrick;font-weight:600;"> ($\boldsymbol{n}$ bits くらいのメモリを使います) </span>

## ベンチマーク

値域 $2^{30}$

| $n = 2^{20}$ 回の 追加 + next クエリ | 所要時間 |
| std::set | 467 ms |
| std::bitset | 254 ms |
| FastSet | 56 ms |

脅威の 8 倍速！
