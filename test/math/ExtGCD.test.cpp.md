---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/ExtGCD.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
      \ (Extended Euclidean algorithm)"
  - icon: ':question:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/math/ExtGCD.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/math/ExtGCD.hpp\"\
    \n// returns gcd(a, b) and assign x, y to integers\n// s.t. ax + by = gcd(a, b)\
    \ and |x| + |y| is minimized\nll extgcd(ll a, ll b, ll& x, ll& y) {\n   // assert(a\
    \ >= 0 && b >= 0);\n   if(!b) return x = 1, y = 0, a;\n   ll d = extgcd(b, a %\
    \ b, y, x);\n   y -= a / b * x;\n   return d;\n}\n#line 4 \"test/math/ExtGCD.test.cpp\"\
    \n\nusing i128 = __int128_t;\ni128 abs(i128 x) { return x < 0 ? -x : x; }\nint\
    \ main() {\n   mt19937_64 rnd;\n   rep(shift, 1, 64) {\n      rep(i, 0, (ll)1e5)\
    \ {\n         ll a = rnd() >> shift;\n         ll b = rnd() >> shift;\n      \
    \   const ll g = gcd(a, b);\n         ll x, y;\n         assert(extgcd(a, b, x,\
    \ y) == g);\n         assert((i128)a * x + (i128)b * y == g);\n         assert(abs(x)\
    \ + abs(y) <= abs((i128)x - b / g) + abs((i128)y + a / g));\n         assert(abs(x)\
    \ + abs(y) <= abs((i128)x + b / g) + abs((i128)y - a / g));\n      }\n   }\n \
    \  puts(\"Hello World\");\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/math/ExtGCD.hpp\"\n\nusing i128\
    \ = __int128_t;\ni128 abs(i128 x) { return x < 0 ? -x : x; }\nint main() {\n \
    \  mt19937_64 rnd;\n   rep(shift, 1, 64) {\n      rep(i, 0, (ll)1e5) {\n     \
    \    ll a = rnd() >> shift;\n         ll b = rnd() >> shift;\n         const ll\
    \ g = gcd(a, b);\n         ll x, y;\n         assert(extgcd(a, b, x, y) == g);\n\
    \         assert((i128)a * x + (i128)b * y == g);\n         assert(abs(x) + abs(y)\
    \ <= abs((i128)x - b / g) + abs((i128)y + a / g));\n         assert(abs(x) + abs(y)\
    \ <= abs((i128)x + b / g) + abs((i128)y - a / g));\n      }\n   }\n   puts(\"\
    Hello World\");\n}\n"
  dependsOn:
  - test/template.hpp
  - src/math/ExtGCD.hpp
  isVerificationFile: true
  path: test/math/ExtGCD.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 02:08:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/ExtGCD.test.cpp
layout: document
redirect_from:
- /verify/test/math/ExtGCD.test.cpp
- /verify/test/math/ExtGCD.test.cpp.html
title: test/math/ExtGCD.test.cpp
---
