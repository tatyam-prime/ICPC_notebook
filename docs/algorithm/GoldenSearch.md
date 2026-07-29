---
title: 黄金分割探索 (Golden-section search)
documentation_of: //src/algorithm/GoldenSearch.hpp
---

## 使い方

- `pair<double, T> golden(double l, double r, function<T(double)> f)`：閉区間 $[l, r]$ 上の連続関数 $f(x)$ の達成する $a$ と極大値 $f(a)$ の組を返す．
    - $f$ が $[l, a]$ 上で**狭義単調増加**，$[a, r]$ 上で**狭義単調減少**であれば，最大値 $(a, f(a))$ が求まる．
- 最小値を求める場合は，`fl < fr` の代わりに `fl > fr` と書けば良い．

## 精度

- $80$ 回反復すると $f$ が $81$ 回評価され，探索区間の幅は $\phi^{80} \approx 5.2 \times 10^{16}$ 倍に縮小する．
