---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/RollingHash.test.cpp
    title: test/string/RollingHash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/string/RollingHash.hpp\"\n// using u64 = uint64_t;\n\
    const u64 mod = INF;\nu64 add(u64 a, u64 b) {\n   a += b;\n   if(a >= mod) a -=\
    \ mod;\n   return a;\n}\nu64 mul(u64 a, u64 b) {\n   auto c = (__uint128_t)a *\
    \ b;\n   return add(c >> 61, c & mod);\n}\nrandom_device rnd;\nconst u64 r = ((u64)rnd()\
    \ << 32 | rnd()) % mod;\nstruct RH {\n   ll n;\n   vector<u64> hs, pw;\n   RH(string\
    \ s) : n(sz(s)), hs(n + 1), pw(n + 1, 1) {\n      for(ll i = 0; i < n; i++) {\n\
    \         pw[i + 1] = mul(pw[i], r);\n         hs[i + 1] = add(mul(hs[i], r),\
    \ s[i]);\n      }\n   }\n   u64 get(ll l, ll r) const { return add(hs[r], mod\
    \ - mul(hs[l], pw[r - l])); }\n};\n"
  code: "// using u64 = uint64_t;\nconst u64 mod = INF;\nu64 add(u64 a, u64 b) {\n\
    \   a += b;\n   if(a >= mod) a -= mod;\n   return a;\n}\nu64 mul(u64 a, u64 b)\
    \ {\n   auto c = (__uint128_t)a * b;\n   return add(c >> 61, c & mod);\n}\nrandom_device\
    \ rnd;\nconst u64 r = ((u64)rnd() << 32 | rnd()) % mod;\nstruct RH {\n   ll n;\n\
    \   vector<u64> hs, pw;\n   RH(string s) : n(sz(s)), hs(n + 1), pw(n + 1, 1) {\n\
    \      for(ll i = 0; i < n; i++) {\n         pw[i + 1] = mul(pw[i], r);\n    \
    \     hs[i + 1] = add(mul(hs[i], r), s[i]);\n      }\n   }\n   u64 get(ll l, ll\
    \ r) const { return add(hs[r], mod - mul(hs[l], pw[r - l])); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/string/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-04-04 09:48:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/RollingHash.test.cpp
documentation_of: src/string/RollingHash.hpp
layout: document
title: Rolling Hash
---
- 参考実装：[tatyam](https://github.com/tatyam-prime/kyopro_library/blob/master/RollingHash.cpp)

## 使い方

- `RH rh(string s)`：文字列 $s$ に対する Rolling Hash を準備する
    - $O(n)$ 時間
- `rh.get(ll l, ll r)`：$s[l:r]$ の hash を求める
    - mod を $P := 2^{61}-1$ とし，基数 $r$ を $[0, P)$ からランダムに選ぶ
    - このとき，長さ $n$ の文字列 $s$ の hash は $(s[0] r^{n-1} + s[1] r^{n-2} + \dots + s[n-1] r^0) \bmod P$ で計算される
    - $O(1)$ 時間

## その他の使い方

- LCP (Longest Common Prefix) を求めたいとき：LCP の長さを二分探索すれば，$O(\log n)$ 時間 / query
- 文字列を辞書順で比較したいとき：LCP の長さを二分探索すれば，$O(\log n)$ 時間 / query

## 衝突確率

- $2$ つの異なる長さ $n$ 以下の文字列が衝突する確率は $\frac{n}{P}$ 以下
    - 参考資料：[Schwartz–Zippel lemma による hash の解析 – noshi91](https://github.com/noshi91/blog/blob/master/pages/hash.pdf)
- $m$ 個の異なる $n$ 文字の文字列がどこかで衝突する確率は，$\frac{n \cdot \binom{m}{2}}{P}$ 以下
    - $(n, m) = (1, 10^6)$ を $100$ ケースやっても $0.002\%$ なので，衝突は基本的に無視できる
