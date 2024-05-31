---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/SuffixArray.hpp
    title: Suffix Array
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
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/string/SuffixArray.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/string/SuffixArray.hpp\"\
    \n// returns pair{sa, lcp}\n// sa \u9577\u3055 n : s[sa[0]:] < s[sa[1]:] < \u2026\
    \ < s[sa[n-1]:]\n// lcp \u9577\u3055 n-1 : lcp[i] = LCP(s[sa[i]:], s[sa[i+1]:])\n\
    auto SA(string s) {\n   ll n = sz(s) + 1, lim = 256;\n   // assert(lim > ranges::max(s));\n\
    \   vector<ll> sa(n), lcp(n), x(all(s) + 1), y(n), ws(max(n, lim)), rk(n);\n \
    \  iota(all(sa), 0);\n   for(ll j = 0, p = 0; p < n; j = max(1LL, j * 2), lim\
    \ = p) {\n      p = j;\n      iota(all(y), n - j);\n      rep(i, 0, n) if(sa[i]\
    \ >= j) y[p++] = sa[i] - j;\n      fill(all(ws), 0);\n      rep(i, 0, n) ws[x[i]]++;\n\
    \      rep(i, 1, lim) ws[i] += ws[i - 1];\n      for(ll i = n; i--;) sa[--ws[x[y[i]]]]\
    \ = y[i];\n      swap(x, y);\n      p = 1;\n      x[sa[0]] = 0;\n      rep(i,\
    \ 1, n) {\n         ll a = sa[i - 1], b = sa[i];\n         x[b] = (y[a] == y[b]\
    \ && y[a + j] == y[b + j]) ? p - 1 : p++;\n      }\n   }\n   rep(i, 1, n) rk[sa[i]]\
    \ = i;\n   for(ll i = 0, k = 0; i < n - 1; lcp[rk[i++]] = k) {\n      if(k) k--;\n\
    \      while(s[i + k] == s[sa[rk[i] - 1] + k]) k++;\n   }\n   sa.erase(begin(sa));\n\
    \   lcp.erase(begin(lcp));\n   return pair{sa, lcp};\n}\n#line 4 \"test/string/SuffixArray.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >>\
    \ S;\n   const ll N = sz(S);\n   auto [sa, lcp] = SA(S);\n   rep(i, 0, N) cout\
    \ << sa[i] << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n#include\
    \ \"test/template.hpp\"\n#include \"src/string/SuffixArray.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   string S;\n   cin >> S;\n   const\
    \ ll N = sz(S);\n   auto [sa, lcp] = SA(S);\n   rep(i, 0, N) cout << sa[i] <<\
    \ \" \\n\"[i + 1 == N];\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/SuffixArray.hpp
  isVerificationFile: true
  path: test/string/SuffixArray.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 19:01:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/SuffixArray.test.cpp
layout: document
redirect_from:
- /verify/test/string/SuffixArray.test.cpp
- /verify/test/string/SuffixArray.test.cpp.html
title: test/string/SuffixArray.test.cpp
---
