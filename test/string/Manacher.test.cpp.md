---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Manacher.hpp
    title: Manacher's algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/string/Manacher.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) {\n   if(a <= b) return 0;\n   a = b;\n   return 1;\n\
    }\nbool chmax(auto& a, auto b) {\n   if(a >= b) return 0;\n   a = b;\n   return\
    \ 1;\n}\n#line 1 \"src/string/Manacher.hpp\"\n// returns array {even-length, odd-length}\
    \ palindromes\n// aaabaaa -> {01100110, 0103010}\n// even-length \u306F\u9577\u3055\
    \ n+1 : \u4E21\u7AEF\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u3082\u306E\u304C\u542B\
    \u307E\u308C\u3066\u3044\u308B\u3053\u3068\u306B\u6CE8\u610F\nauto manacher(string\
    \ s) {\n   ll n = sz(s);\n   array p = {vector<ll>(n + 1), vector<ll>(n)};\n \
    \  rep(z, 0, 2) for(ll i = 0, l = 0, r = 0; i < n; i++) {\n      ll t = r - i\
    \ + !z;\n      if(i < r) p[z][i] = min(t, p[z][l + t]);\n      ll L = i - p[z][i],\
    \ R = i + p[z][i] - !z;\n      while(L >= 1 && R + 1 < n && s[L - 1] == s[R +\
    \ 1]) {\n         p[z][i]++;\n         L--;\n         R++;\n      }\n      if(R\
    \ > r) {\n         l = L;\n         r = R;\n      }\n   }\n   return p;\n}\n#line\
    \ 4 \"test/string/Manacher.test.cpp\"\n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n\
    \   string S;\n   cin >> S;\n   const ll N = sz(S);\n   auto [even, odd] = manacher(S);\n\
    \   rep(i, 1, N * 2) cout << [&] {\n      if(i % 2) return odd[i / 2] * 2 + 1;\n\
    \      else return even[i / 2] * 2;\n   }() << \" \\n\"[i + 1 == N * 2];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"test/template.hpp\"\n#include \"src/string/Manacher.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >> S;\n \
    \  const ll N = sz(S);\n   auto [even, odd] = manacher(S);\n   rep(i, 1, N * 2)\
    \ cout << [&] {\n      if(i % 2) return odd[i / 2] * 2 + 1;\n      else return\
    \ even[i / 2] * 2;\n   }() << \" \\n\"[i + 1 == N * 2];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/Manacher.hpp
  isVerificationFile: true
  path: test/string/Manacher.test.cpp
  requiredBy: []
  timestamp: '2024-05-24 10:03:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/Manacher.test.cpp
layout: document
redirect_from:
- /verify/test/string/Manacher.test.cpp
- /verify/test/string/Manacher.test.cpp.html
title: test/string/Manacher.test.cpp
---
