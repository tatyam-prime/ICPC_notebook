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
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/string/Manacher.hpp\"\
    \n// \u5404\u4F4D\u7F6E\u3067\u306E\u56DE\u6587\u534A\u5F84\u3092\u6C42\u3081\u308B\
    \n// aaabaaa -> 1214121\n// \u5076\u6570\u9577\u306E\u56DE\u6587\u3092\u542B\u3081\
    \u3066\u76F4\u5F84\u3092\u77E5\u308B\u306B\u306F\uFF0CN+1 \u500B\u306E $ \u3092\
    \u633F\u5165\u3057\u3066 1 \u3092\u5F15\u304F\n// $a$a$a$b$a$a$a$ -> 123432181234321\n\
    auto manacher(string s) {\n   ll n = sz(s), i = 0, j = 0;\n   vector<ll> r(n);\n\
    \   while(i < n) {\n      while(i >= j && i + j < n && s[i - j] == s[i + j]) j++;\n\
    \      r[i] = j;\n      ll k = 1;\n      while(i >= k && i + k < n && k + r[i\
    \ - k] < j) {\n         r[i + k] = r[i - k];\n         k++;\n      }\n      i\
    \ += k, j -= k;\n   }\n   return r;\n}\n#line 4 \"test/string/Manacher.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >>\
    \ S;\n   const ll N = sz(S);\n   string T(N * 2 + 1, '$');\n   rep(i, 0, N) T[i\
    \ * 2 + 1] = S[i];\n   auto r = manacher(T);\n   rep(i, 1, N * 2) {\n      if(i\
    \ & 1) cout << r[i] - 1 << \" \\n\"[i + 1 == N * 2];\n      else cout << r[i]\
    \ - 1 << ' ';\n   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include \"test/template.hpp\"\n#include \"src/string/Manacher.hpp\"\n\nint\
    \ main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >> S;\n \
    \  const ll N = sz(S);\n   string T(N * 2 + 1, '$');\n   rep(i, 0, N) T[i * 2\
    \ + 1] = S[i];\n   auto r = manacher(T);\n   rep(i, 1, N * 2) {\n      if(i &\
    \ 1) cout << r[i] - 1 << \" \\n\"[i + 1 == N * 2];\n      else cout << r[i] -\
    \ 1 << ' ';\n   }\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/Manacher.hpp
  isVerificationFile: true
  path: test/string/Manacher.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 19:00:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/Manacher.test.cpp
layout: document
redirect_from:
- /verify/test/string/Manacher.test.cpp
- /verify/test/string/Manacher.test.cpp.html
title: test/string/Manacher.test.cpp
---
