---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FPS/FFT_fast.hpp
    title: FFT (bit reversal ver.)
  - icon: ':heavy_check_mark:'
    path: src/extra/modint_fast.hpp
    title: src/extra/modint_fast.hpp
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
  bundledCode: "#line 1 \"test/FPS/FFT_fast.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n   a = b;\n   return 1;\n\
    }\nbool chmax(auto& a, auto b) {\n   if(a >= b) return 0;\n   a = b;\n   return\
    \ 1;\n}\n#line 1 \"src/extra/modint_fast.hpp\"\nconst uint32_t mod = 998244353;\n\
    struct mm {\n   uint32_t x;\n   mm() : x(0) {}\n   template<class T> mm(T x_)\
    \ : x(x_ % mod) {\n      if(x >= mod) x += mod;\n   }\n   friend mm operator+(mm\
    \ a, mm b) {\n      a.x += b.x;\n      if(a.x >= mod) a.x -= mod;\n      return\
    \ a;\n   }\n   friend mm operator-(mm a, mm b) {\n      a.x -= b.x;\n      if(a.x\
    \ >= mod) a.x += mod;\n      return a;\n   }\n   friend mm operator*(mm a, mm\
    \ b) { return (uint64_t)a.x * b.x; }\n   friend mm operator/(mm a, mm b) { return\
    \ a * b.inv(); }\n   friend mm& operator+=(mm& a, mm b) { return a = a + b; }\n\
    \   friend mm& operator-=(mm& a, mm b) { return a = a - b; }\n   friend mm& operator*=(mm&\
    \ a, mm b) { return a = a * b; }\n   friend mm& operator/=(mm& a, mm b) { return\
    \ a = a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll\
    \ b) const {\n      mm a = *this, c = 1;\n      while(b) {\n         if(b & 1)\
    \ c *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n\
    };\n#line 1 \"src/FPS/FFT_fast.hpp\"\n// {998244353, 3}, {754974721, 11}, {167772161,\
    \ 3}, {469762049, 3}, {2130706433, 3}\nmm g = 3;  // \u539F\u59CB\u6839\nvoid\
    \ fft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static auto z = []\
    \ {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32) {\n       \
    \  z[i - 2] = s * g.pow(mod >> i);\n         s *= g.inv().pow(mod >> i);\n   \
    \   }\n      return z;\n   }();\n   rep(l, 0, lg) {\n      ll w = 1 << (lg - l\
    \ - 1);\n      mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg\
    \ - l);\n         rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w] *\
    \ s;\n            a[i] = x + y;\n            a[i + w] = x - y;\n         }\n \
    \        s *= z[countr_zero<uint64_t>(~k)];\n      }\n   }\n}\n// \u30B3\u30D4\
    \u30DA\nvoid ifft(vector<mm>& a) {\n   ll n = sz(a), lg = __lg(n);\n   static\
    \ auto z = [] {\n      vector<mm> z(30);\n      mm s = 1;\n      rep(i, 2, 32)\
    \ {  // g \u3092\u9006\u6570\u306B\n         z[i - 2] = s * g.inv().pow(mod >>\
    \ i);\n         s *= g.pow(mod >> i);\n      }\n      return z;\n   }();\n   for(ll\
    \ l = lg; l--;) {  // \u9006\u9806\u306B\n      ll w = 1 << (lg - l - 1);\n  \
    \    mm s = 1;\n      rep(k, 0, 1 << l) {\n         ll o = k << (lg - l);\n  \
    \       rep(i, o, o + w) {\n            mm x = a[i], y = a[i + w];  // *s \u3092\
    \u4E0B\u306B\u79FB\u52D5\n            a[i] = x + y;\n            a[i + w] = (x\
    \ - y) * s;\n         }\n         s *= z[countr_zero<uint64_t>(~k)];\n      }\n\
    \   }\n}\nvector<mm> conv(vector<mm> a, vector<mm> b) {\n   if(a.empty() || b.empty())\
    \ return {};\n   size_t s = sz(a) + sz(b) - 1, n = bit_ceil(s);\n   // if(min(sz(a),\
    \ sz(b)) <= 60) \u611A\u76F4\u306B\u639B\u3051\u7B97\n   a.resize(n);\n   b.resize(n);\n\
    \   fft(a);\n   fft(b);\n   mm inv = mm(n).inv();\n   rep(i, 0, n) a[i] *= b[i]\
    \ * inv;\n   ifft(a);\n   a.resize(s);\n   return a;\n}\n#line 5 \"test/FPS/FFT_fast.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, M;\n   cin >> N\
    \ >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A) cin >> a.x;\n   for(mm&\
    \ b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n   rep(i, 0, sz(C))\
    \ cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"test/template.hpp\"\n#include \"src/extra/modint_fast.hpp\"\n#include \"src/FPS/FFT_fast.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, M;\n   cin >> N\
    \ >> M;\n   vector<mm> A(N), B(M);\n   for(mm& a : A) cin >> a.x;\n   for(mm&\
    \ b : B) cin >> b.x;\n\n   auto C = conv(move(A), move(B));\n   rep(i, 0, sz(C))\
    \ cout << C[i].x << \" \\n\"[i + 1 == sz(C)];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/extra/modint_fast.hpp
  - src/FPS/FFT_fast.hpp
  isVerificationFile: true
  path: test/FPS/FFT_fast.test.cpp
  requiredBy: []
  timestamp: '2024-04-04 11:44:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FPS/FFT_fast.test.cpp
layout: document
redirect_from:
- /verify/test/FPS/FFT_fast.test.cpp
- /verify/test/FPS/FFT_fast.test.cpp.html
title: test/FPS/FFT_fast.test.cpp
---
