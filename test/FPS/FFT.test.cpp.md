---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FPS/FFT.hpp
    title: "FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB / \u7573\u307F\u8FBC\
      \u307F)"
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/FPS/FFT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n   a = b;\n   return 1;\n\
    }\nbool chmax(auto& a, auto b) {\n   if(a >= b) return 0;\n   a = b;\n   return\
    \ 1;\n}\n#line 1 \"src/modint/modint.hpp\"\nconst ll mod = 998244353;\nstruct\
    \ mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n      if(x < 0) x += mod;\n\
    \   }\n   friend mm operator+(mm a, mm b) { return a.x + b.x; }\n   friend mm\
    \ operator-(mm a, mm b) { return a.x - b.x; }\n   friend mm operator*(mm a, mm\
    \ b) { return a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return a * b.inv();\
    \ }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift + \u30AF\u30EA\u30C3\u30AF\u3067\
    \u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend mm& operator+=(mm& a, mm b) {\
    \ return a = a.x + b.x; }\n   friend mm& operator-=(mm& a, mm b) { return a =\
    \ a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) { return a = a.x * b.x;\
    \ }\n   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }\n   mm\
    \ inv() const { return pow(mod - 2); }\n   mm pow(ll b) const {\n      mm a =\
    \ *this, c = 1;\n      while(b) {\n         if(b & 1) c *= a;\n         a *= a;\n\
    \         b >>= 1;\n      }\n      return c;\n   }\n};\n#line 1 \"src/FPS/FFT.hpp\"\
    \n// {998244353, 3}, {1811939329, 13}, {2013265921, 31}\nmm g = 3;  // \u539F\u59CB\
    \u6839\nvoid fft(vector<mm>& a) {\n   ll n = sz(a), lg = bit_width<size_t>(n)\
    \ - 1;\n   //   assert((1 << lg) == n);\n   vector<mm> b(n);\n   rep(l, 1, lg\
    \ + 1) {\n      ll w = n >> l;\n      mm s = 1, r = g.pow(mod >> l);\n      for(ll\
    \ u = 0; u < n / 2; u += w) {\n         rep(d, 0, w) {\n            mm x = a[u\
    \ << 1 | d], y = a[u << 1 | w | d] * s;\n            b[u | d] = x + y;\n     \
    \       b[n >> 1 | u | d] = x - y;\n         }\n         s *= r;\n      }\n  \
    \    swap(a, b);\n   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty()\
    \ || b.empty()) return {};\n   size_t s = sz(a) + sz(b) - 1, n = bit_ceil(s);\n\
    \   // if(min(sz(a), sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n\
    \   b.resize(n);\n   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   rep(i,\
    \ 0, n) a[i] *= b[i] * inv;\n   reverse(1 + all(a));\n   fft(a);\n   a.resize(s);\n\
    \   return a;\n}\n#line 5 \"test/FPS/FFT.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   ll N, M;\n   cin >> N >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A)\
    \ cin >> a.x;\n   for(mm& b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n\
    \   rep(i, 0, sz(C)) cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n#include \"src/FPS/FFT.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, M;\n   cin >> N\
    \ >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A) cin >> a.x;\n   for(mm&\
    \ b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n   rep(i, 0, sz(C))\
    \ cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  - src/FPS/FFT.hpp
  isVerificationFile: true
  path: test/FPS/FFT.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 17:02:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/FFT.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/FFT.test.cpp
- /verify/test/FPS/FFT.test.cpp.html
title: test/FPS/FFT.test.cpp
---
