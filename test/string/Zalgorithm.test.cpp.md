---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Zalgorithm.hpp
    title: Z Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/string/Zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n   a = b;\n   return 1;\n\
    }\nbool chmax(auto& a, auto b) {\n   if(a >= b) return 0;\n   a = b;\n   return\
    \ 1;\n}\n#line 1 \"src/string/Zalgorithm.hpp\"\n// Z[i] := LCP(s, s[i:])     \
    \ abacaba -> 7010301\nauto Z(const string& s) {\n   vector<ll> z(sz(s), sz(s));\n\
    \   ll l = -1, r = -1;\n   rep(i, 1, sz(s)) {\n      z[i] = i >= r ? 0 : min(r\
    \ - i, z[i - l]);\n      while(i + z[i] < sz(s) && s[i + z[i]] == s[z[i]]) z[i]++;\n\
    \      if(i + z[i] > r) {\n         l = i;\n         r = i + z[i];\n      }\n\
    \   }\n   return z;\n}\n#line 4 \"test/string/Zalgorithm.test.cpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >> S;\n   auto z\
    \ = Z(S);\n   rep(i, 0, sz(S)) cout << z[i] << \" \\n\"[i + 1 == sz(S)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"test/template.hpp\"\n#include \"src/string/Zalgorithm.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >> S;\n   auto z\
    \ = Z(S);\n   rep(i, 0, sz(S)) cout << z[i] << \" \\n\"[i + 1 == sz(S)];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/Zalgorithm.hpp
  isVerificationFile: true
  path: test/string/Zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2024-04-04 09:48:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/Zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/string/Zalgorithm.test.cpp
- /verify/test/string/Zalgorithm.test.cpp.html
title: test/string/Zalgorithm.test.cpp
---
