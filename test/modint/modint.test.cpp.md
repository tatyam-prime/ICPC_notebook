---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
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
  bundledCode: "#line 1 \"test/modint/modint.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for\
    \ (ll i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\nll sz(const auto&\
    \ a) { return size(a); }\nbool chmin(auto& a, auto b) {\n   if (a <= b) return\
    \ 0;\n   a = b;\n   return 1;\n}\nbool chmax(auto& a, auto b) {\n   if (a >= b)\
    \ return 0;\n   a = b;\n   return 1;\n}\n#line 1 \"src/modint/modint.hpp\"\nconst\
    \ ll mod = 998244353;\nstruct mm {\n   ll x;\n   mm(ll x_ = 0) : x(x_ % mod) {\n\
    \      if (x < 0) x += mod;\n   }\n   friend mm operator+(mm a, mm b) { return\
    \ a.x + b.x; }\n   friend mm operator-(mm a, mm b) { return a.x - b.x; }\n   friend\
    \ mm operator*(mm a, mm b) { return a.x * b.x; }\n   friend mm operator/(mm a,\
    \ mm b) { return a * b.inv(); }\n   // 4 \u884C\u30B3\u30D4\u30DA  Alt + Shift\
    \ + \u30AF\u30EA\u30C3\u30AF\u3067\u8907\u6570\u30AB\u30FC\u30BD\u30EB\n   friend\
    \ mm& operator+=(mm& a, mm b) { return a = a.x + b.x; }\n   friend mm& operator-=(mm&\
    \ a, mm b) { return a = a.x - b.x; }\n   friend mm& operator*=(mm& a, mm b) {\
    \ return a = a.x * b.x; }\n   friend mm& operator/=(mm& a, mm b) { return a =\
    \ a * b.inv(); }\n   mm inv() const { return pow(mod - 2); }\n   mm pow(ll b)\
    \ const {\n      mm a = *this, c = 1;\n      while (b) {\n         if (b & 1)\
    \ c *= a;\n         a *= a;\n         b >>= 1;\n      }\n      return c;\n   }\n\
    };\n#line 4 \"test/modint/modint.test.cpp\"\n\nmt19937 rnd(random_device{}());\n\
    int main() {\n   rep(i, 0, 1e5) {\n      const ll a = rnd() % mod, b = rnd() %\
    \ mod;\n      mm A = a, B = b, C = A * B;\n      assert((A + B).x == (a + b) %\
    \ mod);\n      assert((A - B).x == (a - b + mod) % mod);\n      assert(C.x ==\
    \ (a * b) % mod);\n      assert((A / B.inv()).x == C.x);\n      A = a;\n     \
    \ assert((A += B).x == (a + b) % mod);\n      A = a;\n      assert((A -= B).x\
    \ == (a - b + mod) % mod);\n      A = a;\n      assert((A *= B).x == (a * b) %\
    \ mod);\n      A = a;\n      assert((A /= B.inv()).x == C.x);\n   }\n   puts(\"\
    Hello World\");\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n#include \"src/modint/modint.hpp\"\n\nmt19937\
    \ rnd(random_device{}());\nint main() {\n   rep(i, 0, 1e5) {\n      const ll a\
    \ = rnd() % mod, b = rnd() % mod;\n      mm A = a, B = b, C = A * B;\n      assert((A\
    \ + B).x == (a + b) % mod);\n      assert((A - B).x == (a - b + mod) % mod);\n\
    \      assert(C.x == (a * b) % mod);\n      assert((A / B.inv()).x == C.x);\n\
    \      A = a;\n      assert((A += B).x == (a + b) % mod);\n      A = a;\n    \
    \  assert((A -= B).x == (a - b + mod) % mod);\n      A = a;\n      assert((A *=\
    \ B).x == (a * b) % mod);\n      A = a;\n      assert((A /= B.inv()).x == C.x);\n\
    \   }\n   puts(\"Hello World\");\n}\n"
  dependsOn:
  - test/template.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/modint/modint.test.cpp
  requiredBy: []
  timestamp: '2024-02-14 16:35:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modint/modint.test.cpp
layout: document
redirect_from:
- /verify/test/modint/modint.test.cpp
- /verify/test/modint/modint.test.cpp.html
title: test/modint/modint.test.cpp
---
