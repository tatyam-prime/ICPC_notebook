---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/KMP.hpp
    title: "KMP \u6CD5 (Knuth\u2013Morris\u2013Pratt algorithm)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/string/KMP.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a, b) for(ll\
    \ i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\n#define sz(a) ssize(a)\n\
    bool chmin(auto& a, auto b) { return a > b ? a = b, 1 : 0; }\nbool chmax(auto&\
    \ a, auto b) { return a < b ? a = b, 1 : 0; }\n#line 1 \"src/string/KMP.hpp\"\n\
    // kmp[i] := max{ l \u2264 i | s[:l] == s[(i+1)-l:i+1] }\n// abacaba -> 0010123\n\
    auto KMP(string s) {\n   vector<ll> p(sz(s));\n   rep(i, 1, sz(s)) {\n      ll\
    \ g = p[i - 1];\n      while(g && s[i] != s[g]) g = p[g - 1];\n      p[i] = g\
    \ + (s[i] == s[g]);\n   }\n   return p;\n}\n#line 4 \"test/string/KMP.test.cpp\"\
    \n\nint main() {\n   cin.tie(0)->sync_with_stdio(0);\n   string S, T;\n   cin\
    \ >> S >> T;\n   auto s = T + '$' + S;\n   auto kmp = KMP(s);\n\n   rep(i, sz(s)\
    \ - sz(S), sz(s)) {\n      if(kmp[i] == sz(T)) cout << i - sz(T) * 2 << '\\n';\n\
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n#include \"test/template.hpp\"\n#include \"src/string/KMP.hpp\"\n\nint main()\
    \ {\n   cin.tie(0)->sync_with_stdio(0);\n   string S, T;\n   cin >> S >> T;\n\
    \   auto s = T + '$' + S;\n   auto kmp = KMP(s);\n\n   rep(i, sz(s) - sz(S), sz(s))\
    \ {\n      if(kmp[i] == sz(T)) cout << i - sz(T) * 2 << '\\n';\n   }\n}\n"
  dependsOn:
  - test/template.hpp
  - src/string/KMP.hpp
  isVerificationFile: true
  path: test/string/KMP.test.cpp
  requiredBy: []
  timestamp: '2024-05-31 19:00:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/KMP.test.cpp
layout: document
redirect_from:
- /verify/test/string/KMP.test.cpp
- /verify/test/string/KMP.test.cpp.html
title: test/string/KMP.test.cpp
---
