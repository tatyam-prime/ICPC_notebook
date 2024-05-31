---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/BinaryGCD.hpp
    title: Binary GCD
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/math/BinaryGCD.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 3 \"test/math/BinaryGCD.test.cpp\"\
    \nusing u64 = uint64_t;\n#line 1 \"src/math/BinaryGCD.hpp\"\nu64 ctz(u64 x) {\
    \ return countr_zero(x); }\nu64 binary_gcd(u64 x, u64 y) {\n   if(!x || !y) return\
    \ x | y;\n   u64 n = ctz(x), m = ctz(y);\n   x >>= n, y >>= m;\n   while(x !=\
    \ y) {\n      if(x > y) x = (x - y) >> ctz(x - y);\n      else y = (y - x) >>\
    \ ctz(y - x);\n   }\n   return x << min(n, m);\n}\n#line 5 \"test/math/BinaryGCD.test.cpp\"\
    \n\nint main() {\n   mt19937_64 rnd;\n   rep(shift, 0, 64) {\n      rep(i, 0,\
    \ (ll)1e5) {\n         u64 a = rnd() >> shift, b = rnd() >> shift;\n         assert(gcd(a,\
    \ b) == binary_gcd(a, b));\n      }\n   }\n   puts(\"Hello World\");\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\nusing u64 = uint64_t;\n#include \"src/math/BinaryGCD.hpp\"\
    \n\nint main() {\n   mt19937_64 rnd;\n   rep(shift, 0, 64) {\n      rep(i, 0,\
    \ (ll)1e5) {\n         u64 a = rnd() >> shift, b = rnd() >> shift;\n         assert(gcd(a,\
    \ b) == binary_gcd(a, b));\n      }\n   }\n   puts(\"Hello World\");\n}\n"
  dependsOn:
  - test/template.hpp
  - src/math/BinaryGCD.hpp
  isVerificationFile: true
  path: test/math/BinaryGCD.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 01:21:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/BinaryGCD.test.cpp
layout: document
redirect_from:
- /verify/test/math/BinaryGCD.test.cpp
- /verify/test/math/BinaryGCD.test.cpp.html
title: test/math/BinaryGCD.test.cpp
---
