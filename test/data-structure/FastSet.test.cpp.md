---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/FastSet.hpp
    title: "\u9AD8\u901F bitset (64 \u5206\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/data-structure/FastSet.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#line 1 \"test/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nconst\
    \ ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll i = a; i < (b); i++)\n\
    #define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\nbool chmin(auto& a, auto\
    \ b) {\n   if(a <= b) return 0;\n   a = b;\n   return 1;\n}\nbool chmax(auto&\
    \ a, auto b) {\n   if(a >= b) return 0;\n   a = b;\n   return 1;\n}\n#line 3 \"\
    test/data-structure/FastSet.test.cpp\"\nusing u64 = uint64_t;\n#line 1 \"src/data-structure/FastSet.hpp\"\
    \n// using u64 = uint64_t;\nconst u64 B = 64;\nstruct FastSet {\n   u64 n;\n \
    \  vector<vector<u64>> a;\n   FastSet(u64 n_) : n(n_) {\n      do a.emplace_back(n_\
    \ = (n_ + B - 1) / B);\n      while(n_ > 1);\n   }\n   // bool operator[](ll i)\
    \ const { return a[0][i / B] >> (i % B) & 1; }\n   void set(ll i) {\n      for(auto&\
    \ v : a) {\n         v[i / B] |= 1ULL << (i % B);\n         i /= B;\n      }\n\
    \   }\n   void reset(ll i) {\n      for(auto& v : a) {\n         v[i / B] &= ~(1ULL\
    \ << (i % B));\n         if(v[i / B]) break;\n         i /= B;\n      }\n   }\n\
    \   ll next(ll i) {  // i \u3092\u8D85\u3048\u308B\u6700\u2F29\u306E\u8981\u7D20\
    \n      rep(h, 0, sz(a)) {\n         i++;\n         if(i / B >= sz(a[h])) break;\n\
    \         u64 d = a[h][i / B] >> (i % B);\n         if(d) {\n            i +=\
    \ countr_zero(d);\n            while(h--) i = i * B + countr_zero(a[h][i]);\n\
    \            return i;\n         }\n         i /= B;\n      }\n      return n;\n\
    \   }\n   ll prev(ll i) {  // i \u3088\u308A\u5C0F\u3055\u3044\u6700\u2F24\u306E\
    \u8981\u7D20\n      rep(h, 0, sz(a)) {\n         i--;\n         if(i < 0) break;\n\
    \         u64 d = a[h][i / B] << (~i % B);\n         if(d) {\n            i -=\
    \ countl_zero(d);\n            while(h--) i = i * B + __lg(a[h][i]);\n       \
    \     return i;\n         }\n         i /= B;\n      }\n      return -1;\n   }\n\
    };\n#line 5 \"test/data-structure/FastSet.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   ll N, Q;\n   cin >> N >> Q;\n   string S;\n   cin >> S;\n   FastSet s(N);\n\
    \   rep(i, 0, N) if(S[i] == '1') s.set(i);\n   while(Q--) {\n      ll c, k;\n\
    \      cin >> c >> k;\n      if(c == 0) s.set(k);\n      if(c == 1) s.reset(k);\n\
    \      if(c == 2) cout << (s.a[0][k / B] >> (k % B) & 1) << '\\n';\n      if(c\
    \ == 3) {\n         ll ans = s.next(k - 1);\n         cout << (ans == N ? -1 :\
    \ ans) << '\\n';\n      }\n      if(c == 4) cout << s.prev(k + 1) << '\\n';\n\
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"test/template.hpp\"\nusing u64 = uint64_t;\n#include \"src/data-structure/FastSet.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   ll N, Q;\n   cin >> N\
    \ >> Q;\n   string S;\n   cin >> S;\n   FastSet s(N);\n   rep(i, 0, N) if(S[i]\
    \ == '1') s.set(i);\n   while(Q--) {\n      ll c, k;\n      cin >> c >> k;\n \
    \     if(c == 0) s.set(k);\n      if(c == 1) s.reset(k);\n      if(c == 2) cout\
    \ << (s.a[0][k / B] >> (k % B) & 1) << '\\n';\n      if(c == 3) {\n         ll\
    \ ans = s.next(k - 1);\n         cout << (ans == N ? -1 : ans) << '\\n';\n   \
    \   }\n      if(c == 4) cout << s.prev(k + 1) << '\\n';\n   }\n}\n"
  dependsOn:
  - test/template.hpp
  - src/data-structure/FastSet.hpp
  isVerificationFile: true
  path: test/data-structure/FastSet.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 17:02:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data-structure/FastSet.test.cpp
layout: document
redirect_from:
- /verify/test/data-structure/FastSet.test.cpp
- /verify/test/data-structure/FastSet.test.cpp.html
title: test/data-structure/FastSet.test.cpp
---
