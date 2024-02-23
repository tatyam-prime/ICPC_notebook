---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/modint/BarrettReduction.hpp
    title: src/modint/BarrettReduction.hpp
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
  bundledCode: "#line 1 \"test/modint/BarrettReduction.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n#line\
    \ 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\nll sz(const auto& a)\
    \ { return size(a); }\nbool chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n\
    \   a = b;\n   return 1;\n}\nbool chmax(auto& a, auto b) {\n   if(a >= b) return\
    \ 0;\n   a = b;\n   return 1;\n}\n#line 3 \"test/modint/BarrettReduction.test.cpp\"\
    \nusing u64 = uint64_t;\n#line 1 \"src/modint/BarrettReduction.hpp\"\n// using\
    \ u64 = uint64_t;\nstruct Barrett {  // mod < 2^32\n   u64 m, im;\n   Barrett(u64\
    \ mod) : m(mod), im(-1ULL / m + 1) {}\n   // input: a * b < 2^64, output: a *\
    \ b % mod\n   u64 mul(u64 a, u64 b) const {\n      a *= b;\n      u64 x = ((__uint128_t)a\
    \ * im) >> 64;\n      a -= x * m;\n      if((ll)a < 0) a += m;\n      return a;\n\
    \   }\n};\n#line 5 \"test/modint/BarrettReduction.test.cpp\"\n\nmt19937 rnd(random_device{}());\n\
    int main() {\n   rep(i, 0, 1e5) {\n      const u64 mod = rnd(), a = rnd(), b =\
    \ rnd(), ans1 = Barrett(mod).mul(a, b), ans2 = a * b % mod;\n      if(mod == 0)\
    \ continue;\n      assert(ans1 == ans2);\n   }\n   puts(\"Hello World\");\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\nusing u64 = uint64_t;\n#include \"src/modint/BarrettReduction.hpp\"\
    \n\nmt19937 rnd(random_device{}());\nint main() {\n   rep(i, 0, 1e5) {\n     \
    \ const u64 mod = rnd(), a = rnd(), b = rnd(), ans1 = Barrett(mod).mul(a, b),\
    \ ans2 = a * b % mod;\n      if(mod == 0) continue;\n      assert(ans1 == ans2);\n\
    \   }\n   puts(\"Hello World\");\n}\n"
  dependsOn:
  - test/template.hpp
  - src/modint/BarrettReduction.hpp
  isVerificationFile: true
  path: test/modint/BarrettReduction.test.cpp
  requiredBy: []
  timestamp: '2024-02-23 13:57:10+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modint/BarrettReduction.test.cpp
layout: document
redirect_from:
- /verify/test/modint/BarrettReduction.test.cpp
- /verify/test/modint/BarrettReduction.test.cpp.html
title: test/modint/BarrettReduction.test.cpp
---
