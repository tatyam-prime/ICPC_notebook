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
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\nll sz(const auto& a)\
    \ { return size(a); }\nbool chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n\
    \   a = b;\n   return 1;\n}\nbool chmax(auto& a, auto b) {\n   if(a >= b) return\
    \ 0;\n   a = b;\n   return 1;\n}\n#line 1 \"src/modint/modint.hpp\"\nconst ll\
    \ mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n\
    \      if(x < 0) x += mod;\n   }\n   friend mm operator+(mm a, mm b) { return\
    \ a.x + b.x; }\n   friend mm operator-(mm a, mm b) { return a.x - b.x; }\n   friend\
    \ mm operator*(mm a, mm b) { return a.x * b.x; }\n   friend mm operator/(mm a,\
    \ mm b) { return a * b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift\
    \ + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend\
    \ mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm&\
    \ a, mm b) { return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) {\
    \ return a = a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a =\
    \ a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b)\
    \ const {\n      mm a = *this, c = 1;\n      while(b) {\n         if(b & 1) c\
    \ *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n\
    };\n#line 1 \"src/FPS/FFT.hpp\"\n// {998244353, 3}, {754974721, 11}, {167772161,\
    \ 3}, {469762049, 3}, {2130706433, 3}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid\
    \ fft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static auto z = []\
    \ {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32) {\n       \
    \  z[i - 2] = s * g.pow(mod >> i);\n         s *= g.inv().pow(mod >> i);\n   \
    \   }\n      return z;\n   }();\n   rep(l, 0, lg) {\n      ll w = 1 << (lg - l\
    \ - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg\
    \ - l);\n         rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w] *\
    \ s;\n            a[i] = x + y;\n            a[i + w] = x - y;\n         }\n \
    \        s *= z[__builtin_ctzll(~k)];\n      }\n   }\n}\n// \u30B3\u30D4\u30DA\
    \nvoid ifft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static auto z\
    \ = [] {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32) {  //\
    \ g \u3092\u9006\u6570\u306B\n         z[i - 2] = s * g.inv().pow(mod >> i);\n\
    \         s *= g.pow(mod >> i);\n      }\n      return z;\n   }();\n   for(ll\
    \ l = lg; l--;) {  // \u9006\u9806\u306B\n      ll w = 1 << (lg - l - 1);\n  \
    \    mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg - l);\n  \
    \       rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w];  // *s \u3092\
    \u79FB\u52D5\n            a[i] = x + y;\n            a[i + w] = (x - y) * s;\n\
    \         }\n         s *= z[__builtin_ctzll(~k)];\n      }\n   }\n}\nvector<mm>\
    \ conv(vector<mm> a, vector<mm> b) {\n   if(a.empty() || b.empty()) return {};\n\
    \   size_t n_ = sz(a) + sz(b) - 1, n = bit_ceil(n_);\n   // if(min(sz(a), sz(b))\
    \ <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n\
    \   fft(a);\n   fft(b);\n   mm x = mm(n).inv();\n   rep(i, 0, n) a[i] *= b[i]\
    \ * x;\n   ifft(a);\n   a.resize(n_);\n   return a;\n}\n#line 5 \"test/FPS/FFT.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, M;\n   cin >> N\
    \ >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A) cin >> a.x;\n   for(mm&\
    \ b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n   rep(i, 0, sz(C))\
    \ cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
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
  timestamp: '2024-02-23 08:47:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/FFT.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/FFT.test.cpp
- /verify/test/FPS/FFT.test.cpp.html
title: test/FPS/FFT.test.cpp
---
