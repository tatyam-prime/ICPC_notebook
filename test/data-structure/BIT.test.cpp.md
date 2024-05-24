---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BIT.hpp
    title: BIT (Fenwick Tree)
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/data-structure/BIT.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n   a = b;\n   return 1;\n\
    }\nbool chmax(auto& a, auto b) {\n   if(a >= b) return 0;\n   a = b;\n   return\
    \ 1;\n}\n#line 1 \"src/data-structure/BIT.hpp\"\nstruct BIT {\n   vector<ll> a;\n\
    \   BIT(ll n) : a(n + 1) {}\n   void add(ll i, ll x) {  // A[i] += x\n      i++;\n\
    \      while(i < sz(a)) {\n         a[i] += x;\n         i += i & -i;\n      }\n\
    \   }\n   ll sum(ll r) {\n      ll s = 0;\n      while(r) {\n         s += a[r];\n\
    \         r -= r & -r;\n      }\n      return s;\n   }\n   ll sum(ll l, ll r)\
    \ {  // sum of A[l, r)\n      return sum(r) - sum(l);\n   }\n};\n#line 4 \"test/data-structure/BIT.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\n   ll N, Q;\n   cin >>\
    \ N >> Q;\n\n   BIT A(N);\n   rep(i, 0, N) {\n      ll a;\n      cin >> a;\n \
    \     A.add(i, a);\n   }\n\n   while(Q--) {\n      ll a, b, c;\n      cin >> a\
    \ >> b >> c;\n      if(a == 0) A.add(b, c);\n      else cout << A.sum(b, c) <<\
    \ '\\n';\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"test/template.hpp\"\n#include \"src/data-structure/BIT.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n\n   ll N, Q;\n   cin >> N >>\
    \ Q;\n\n   BIT A(N);\n   rep(i, 0, N) {\n      ll a;\n      cin >> a;\n      A.add(i,\
    \ a);\n   }\n\n   while(Q--) {\n      ll a, b, c;\n      cin >> a >> b >> c;\n\
    \      if(a == 0) A.add(b, c);\n      else cout << A.sum(b, c) << '\\n';\n   }\n\
    }\n"
  dependsOn:
  - test/template.hpp
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/data-structure/BIT.test.cpp
  requiredBy: []
  timestamp: '2024-05-24 10:03:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/BIT.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/BIT.test.cpp
- /verify/test/data-structure/BIT.test.cpp.html
title: test/data-structure/BIT.test.cpp
---
