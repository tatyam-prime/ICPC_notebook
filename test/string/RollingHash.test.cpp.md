---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/RollingHash.hpp
    title: Rolling Hash
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/string/RollingHash.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 3 \"test/string/RollingHash.test.cpp\"\
    \nusing u64 = uint64_t;\n#line 1 \"src/string/RollingHash.hpp\"\n// using u64\
    \ = uint64_t;\nconst u64 mod = INF;\nu64 add(u64 a, u64 b) {\n   a += b;\n   if(a\
    \ >= mod) a -= mod;\n   return a;\n}\nu64 mul(u64 a, u64 b) {\n   auto c = (__uint128_t)a\
    \ * b;\n   return add(c >> 61, c & mod);\n}\nrandom_device rnd;\nconst u64 r =\
    \ ((u64)rnd() << 32 | rnd()) % mod;\nstruct RH {\n   ll n;\n   vector<u64> hs,\
    \ pw;\n   RH(string s) : n(sz(s)), hs(n + 1), pw(n + 1, 1) {\n      rep(i, 0,\
    \ n) {\n         pw[i + 1] = mul(pw[i], r);\n         hs[i + 1] = add(mul(hs[i],\
    \ r), s[i]);\n      }\n   }\n   u64 get(ll l, ll r) const { return add(hs[r],\
    \ mod - mul(hs[l], pw[r - l])); }\n};\n#line 5 \"test/string/RollingHash.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >>\
    \ S;\n   RH rh(S);\n   const ll N = sz(S);\n   auto LCP = [&](ll i, ll j) {\n\
    \      ll ok = 0, ng = N + 1 - j;\n      while(ng - ok > 1) {\n         const\
    \ ll mid = (ok + ng) / 2;\n         (rh.get(i, i + mid) == rh.get(j, j + mid)\
    \ ? ok : ng) = mid;\n      }\n      return ok;\n   };\n   rep(i, 0, N) cout <<\
    \ LCP(0, i) << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"test/template.hpp\"\nusing u64 = uint64_t;\n#include \"src/string/RollingHash.hpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >>\
    \ S;\n   RH rh(S);\n   const ll N = sz(S);\n   auto LCP = [&](ll i, ll j) {\n\
    \      ll ok = 0, ng = N + 1 - j;\n      while(ng - ok > 1) {\n         const\
    \ ll mid = (ok + ng) / 2;\n         (rh.get(i, i + mid) == rh.get(j, j + mid)\
    \ ? ok : ng) = mid;\n      }\n      return ok;\n   };\n   rep(i, 0, N) cout <<\
    \ LCP(0, i) << \" \\n\"[i + 1 == N];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/RollingHash.hpp
  isVerificationFile: true
  path: test/string/RollingHash.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 19:00:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/RollingHash.test.cpp
layout: document
redirect_from:
- /verify/test/string/RollingHash.test.cpp
- /verify/test/string/RollingHash.test.cpp.html
title: test/string/RollingHash.test.cpp
---
