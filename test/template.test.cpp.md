---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 1 \"test/template.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 3 \"test/template.test.cpp\"\
    \n\nint main() {\n    ll a = 0;\n    assert(chmin(a, 1) == 0);\n    assert(chmax(a,\
    \ 1) == 1);\n    assert(chmax(a, 1) == 0);\n    assert(chmin(a, 0) == 1);\n  \
    \  puts(\"Hello World\");\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n#include \"test/template.hpp\"\n\nint main() {\n    ll a = 0;\n    assert(chmin(a,\
    \ 1) == 0);\n    assert(chmax(a, 1) == 1);\n    assert(chmax(a, 1) == 0);\n  \
    \  assert(chmin(a, 0) == 1);\n    puts(\"Hello World\");\n}\n"
  dependsOn:
  - test/template.hpp
  isVerificationFile: true
  path: test/template.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 23:58:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/template.test.cpp
layout: document
redirect_from:
- /verify/test/template.test.cpp
- /verify/test/template.test.cpp.html
title: test/template.test.cpp
---
