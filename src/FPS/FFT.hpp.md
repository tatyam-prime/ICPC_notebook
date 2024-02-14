---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: test/template.hpp
    title: test/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\nconst ll INF = LLONG_MAX / 4;\n#define rep(i, a,\
    \ b) for (ll i = a; i < (b); i++)\n#define all(a) begin(a), end(a)\nll sz(const\
    \ auto& a) { return size(a); }\nbool chmin(auto& a, auto b) {\n   if (a <= b)\
    \ return 0;\n   a = b;\n   return 1;\n}\nbool chmax(auto& a, auto b) {\n   if\
    \ (a >= b) return 0;\n   a = b;\n   return 1;\n}\n#line 2 \"src/FPS/FFT.hpp\"\n\
    \nconstexpr pair<ll, ll> inv_gcd(ll a, ll b) {\n   a = safe_mod(a, b);\n   if\
    \ (a == 0) return {b, 0};\n\n   ll s = b, t = a;\n   ll m0 = 0, m1 = 1;\n\n  \
    \ while (t) {\n      ll u = s / t;\n      s -= t * u;\n      m0 -= m1 * u;  //\
    \ |m1 * u| <= |m1| * s <= b\n\n      auto tmp = s;\n      s = t;\n      t = tmp;\n\
    \      tmp = m0;\n      m0 = m1;\n      m1 = tmp;\n   }\n   if (m0 < 0) m0 +=\
    \ b / s;\n   return {s, m0};\n}\n\nusing ull = uint64_t;\null floor_sum_unsigned(ull\
    \ n, ull m, ull a, ull b) {\n   ull ans = 0;\n   while (true) {\n      if (a >=\
    \ m) {\n         ans += n * (n - 1) / 2 * (a / m);\n         a %= m;\n      }\n\
    \      if (b >= m) {\n         ans += n * (b / m);\n         b %= m;\n      }\n\
    \n      ull y_max = a * n + b;\n      if (y_max < m) break;\n      n = (ull)(y_max\
    \ / m);\n      b = (ull)(y_max % m);\n      swap(m, a);\n   }\n   return ans;\n\
    }\n\nstruct fft_info {\n   static constexpr int rank2 = countr_zero_constexpr(mod\
    \ - 1);\n   array<mm, rank2 + 1> root;   // root[i]^(2^i) == 1\n   array<mm, rank2\
    \ + 1> iroot;  // root[i] * iroot[i] == 1\n\n   array<mm, max(0, rank2 - 2 + 1)>\
    \ rate2;\n   array<mm, max(0, rank2 - 2 + 1)> irate2;\n\n   array<mm, max(0, rank2\
    \ - 3 + 1)> rate3;\n   array<mm, max(0, rank2 - 3 + 1)> irate3;\n\n   fft_info()\
    \ {\n      root[rank2] = mm(g).pow((mod - 1) >> rank2);\n      iroot[rank2] =\
    \ root[rank2].inv();\n      for (int i = rank2 - 1; i >= 0; i--) {\n         root[i]\
    \ = root[i + 1] * root[i + 1];\n         iroot[i] = iroot[i + 1] * iroot[i + 1];\n\
    \      }\n\n      {\n         mm prod = 1, iprod = 1;\n         for (int i = 0;\
    \ i <= rank2 - 2; i++) {\n            rate2[i] = root[i + 2] * prod;\n       \
    \     irate2[i] = iroot[i + 2] * iprod;\n            prod *= iroot[i + 2];\n \
    \           iprod *= root[i + 2];\n         }\n      }\n      {\n         mm prod\
    \ = 1, iprod = 1;\n         for (int i = 0; i <= rank2 - 3; i++) {\n         \
    \   rate3[i] = root[i + 3] * prod;\n            irate3[i] = iroot[i + 3] * iprod;\n\
    \            prod *= iroot[i + 3];\n            iprod *= root[i + 3];\n      \
    \   }\n      }\n   }\n};\n\nvoid butterfly(vector<mm>& a) {\n   int n = int(a.size());\n\
    \   int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mm> info;\n\
    \n   int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n   while\
    \ (len < h) {\n      if (h - len == 1) {\n         int p = 1 << (h - len - 1);\n\
    \         mm rot = 1;\n         for (int s = 0; s < (1 << len); s++) {\n     \
    \       int offset = s << (h - len);\n            for (int i = 0; i < p; i++)\
    \ {\n               auto l = a[i + offset];\n               auto r = a[i + offset\
    \ + p] * rot;\n               a[i + offset] = l + r;\n               a[i + offset\
    \ + p] = l - r;\n            }\n            if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~(uint)(s))];\n\
    \         }\n         len++;\n      } else {\n         int p = 1 << (h - len -\
    \ 2);\n         mm rot = 1, imag = info.root[2];\n         for (int s = 0; s <\
    \ (1 << len); s++) {\n            mm rot2 = rot * rot;\n            mm rot3 =\
    \ rot2 * rot;\n            int offset = s << (h - len);\n            for (int\
    \ i = 0; i < p; i++) {\n               auto mod2 = 1ULL * mod * mod;\n       \
    \        auto a0 = 1ULL * a[i + offset].val();\n               auto a1 = 1ULL\
    \ * a[i + offset + p].val() * rot.val();\n               auto a2 = 1ULL * a[i\
    \ + offset + 2 * p].val() * rot2.val();\n               auto a3 = 1ULL * a[i +\
    \ offset + 3 * p].val() * rot3.val();\n               auto a1na3imag = 1ULL *\
    \ mm(a1 + mod2 - a3).val() * imag.val();\n               auto na2 = mod2 - a2;\n\
    \               a[i + offset] = a0 + a2 + a1 + a3;\n               a[i + offset\
    \ + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n               a[i + offset +\
    \ 2 * p] = a0 + na2 + a1na3imag;\n               a[i + offset + 3 * p] = a0 +\
    \ na2 + (mod2 - a1na3imag);\n            }\n            if (s + 1 != (1 << len))\
    \ rot *= info.rate3[countr_zero(~(uint)(s))];\n         }\n         len += 2;\n\
    \      }\n   }\n}\n\nvoid butterfly_inv(vector<mm>& a) {\n   int n = int(a.size());\n\
    \   int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mm> info;\n\
    \n   int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n   while\
    \ (len) {\n      if (len == 1) {\n         int p = 1 << (h - len);\n         mm\
    \ irot = 1;\n         for (int s = 0; s < (1 << (len - 1)); s++) {\n         \
    \   int offset = s << (h - len + 1);\n            for (int i = 0; i < p; i++)\
    \ {\n               auto l = a[i + offset];\n               auto r = a[i + offset\
    \ + p];\n               a[i + offset] = l + r;\n               a[i + offset +\
    \ p] = (ull)(mod + l.val() - r.val()) * irot.val();\n               ;\n      \
    \      }\n            if (s + 1 != (1 << (len - 1))) irot *= info.irate2[countr_zero(~(uint)(s))];\n\
    \         }\n         len--;\n      } else {\n         int p = 1 << (h - len);\n\
    \         mm irot = 1, iimag = info.iroot[2];\n         for (int s = 0; s < (1\
    \ << (len - 2)); s++) {\n            mm irot2 = irot * irot;\n            mm irot3\
    \ = irot2 * irot;\n            int offset = s << (h - len + 2);\n            for\
    \ (int i = 0; i < p; i++) {\n               auto a0 = 1ULL * a[i + offset + 0\
    \ * p].val();\n               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n\
    \               auto a2 = 1ULL * a[i + offset + 2 * p].val();\n              \
    \ auto a3 = 1ULL * a[i + offset + 3 * p].val();\n\n               auto a2na3iimag\
    \ = 1ULL * mm((mod + a2 - a3) * iimag.val()).val();\n\n               a[i + offset]\
    \ = a0 + a1 + a2 + a3;\n               a[i + offset + 1 * p] = (a0 + (mod - a1)\
    \ + a2na3iimag) * irot.val();\n               a[i + offset + 2 * p] = (a0 + a1\
    \ + (mod - a2) + (mod - a3)) * irot2.val();\n               a[i + offset + 3 *\
    \ p] = (a0 + (mod - a1) + (mod - a2na3iimag)) * irot3.val();\n            }\n\
    \            if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~(uint)(s))];\n\
    \         }\n         len -= 2;\n      }\n   }\n}\n\nvector<mm> convolution_naive(const\
    \ vector<mm>& a, const vector<mm>& b) {\n   int n = int(a.size()), m = int(b.size());\n\
    \   vector<mm> ans(n + m - 1);\n   if (n < m) {\n      for (int j = 0; j < m;\
    \ j++) {\n         for (int i = 0; i < n; i++) { ans[i + j] += a[i] * b[j]; }\n\
    \      }\n   } else {\n      for (int i = 0; i < n; i++) {\n         for (int\
    \ j = 0; j < m; j++) { ans[i + j] += a[i] * b[j]; }\n      }\n   }\n   return\
    \ ans;\n}\n\nvector<mm> convolution_fft(vector<mm> a, vector<mm> b) {\n   int\
    \ n = int(a.size()), m = int(b.size());\n   int z = (int)internal::bit_ceil((uint)(n\
    \ + m - 1));\n   a.resize(z);\n   internal::butterfly(a);\n   b.resize(z);\n \
    \  internal::butterfly(b);\n   for (int i = 0; i < z; i++) { a[i] *= b[i]; }\n\
    \   internal::butterfly_inv(a);\n   a.resize(n + m - 1);\n   mm iz = mm(z).inv();\n\
    \   for (int i = 0; i < n + m - 1; i++) a[i] *= iz;\n   return a;\n}\n\nvector<mm>\
    \ convolution(const vector<mm>& a, const vector<mm>& b) {\n   int n = int(a.size()),\
    \ m = int(b.size());\n   if (!n || !m) return {};\n\n   int z = (int)internal::bit_ceil((uint)(n\
    \ + m - 1));\n   assert((mod - 1) % z == 0);\n\n   if (min(n, m) <= 60) return\
    \ convolution_naive(a, b);\n   return internal::convolution_fft(a, b);\n}\n"
  code: "#include \"test/template.hpp\"\n\nconstexpr pair<ll, ll> inv_gcd(ll a, ll\
    \ b) {\n   a = safe_mod(a, b);\n   if (a == 0) return {b, 0};\n\n   ll s = b,\
    \ t = a;\n   ll m0 = 0, m1 = 1;\n\n   while (t) {\n      ll u = s / t;\n     \
    \ s -= t * u;\n      m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n      auto\
    \ tmp = s;\n      s = t;\n      t = tmp;\n      tmp = m0;\n      m0 = m1;\n  \
    \    m1 = tmp;\n   }\n   if (m0 < 0) m0 += b / s;\n   return {s, m0};\n}\n\nusing\
    \ ull = uint64_t;\null floor_sum_unsigned(ull n, ull m, ull a, ull b) {\n   ull\
    \ ans = 0;\n   while (true) {\n      if (a >= m) {\n         ans += n * (n - 1)\
    \ / 2 * (a / m);\n         a %= m;\n      }\n      if (b >= m) {\n         ans\
    \ += n * (b / m);\n         b %= m;\n      }\n\n      ull y_max = a * n + b;\n\
    \      if (y_max < m) break;\n      n = (ull)(y_max / m);\n      b = (ull)(y_max\
    \ % m);\n      swap(m, a);\n   }\n   return ans;\n}\n\nstruct fft_info {\n   static\
    \ constexpr int rank2 = countr_zero_constexpr(mod - 1);\n   array<mm, rank2 +\
    \ 1> root;   // root[i]^(2^i) == 1\n   array<mm, rank2 + 1> iroot;  // root[i]\
    \ * iroot[i] == 1\n\n   array<mm, max(0, rank2 - 2 + 1)> rate2;\n   array<mm,\
    \ max(0, rank2 - 2 + 1)> irate2;\n\n   array<mm, max(0, rank2 - 3 + 1)> rate3;\n\
    \   array<mm, max(0, rank2 - 3 + 1)> irate3;\n\n   fft_info() {\n      root[rank2]\
    \ = mm(g).pow((mod - 1) >> rank2);\n      iroot[rank2] = root[rank2].inv();\n\
    \      for (int i = rank2 - 1; i >= 0; i--) {\n         root[i] = root[i + 1]\
    \ * root[i + 1];\n         iroot[i] = iroot[i + 1] * iroot[i + 1];\n      }\n\n\
    \      {\n         mm prod = 1, iprod = 1;\n         for (int i = 0; i <= rank2\
    \ - 2; i++) {\n            rate2[i] = root[i + 2] * prod;\n            irate2[i]\
    \ = iroot[i + 2] * iprod;\n            prod *= iroot[i + 2];\n            iprod\
    \ *= root[i + 2];\n         }\n      }\n      {\n         mm prod = 1, iprod =\
    \ 1;\n         for (int i = 0; i <= rank2 - 3; i++) {\n            rate3[i] =\
    \ root[i + 3] * prod;\n            irate3[i] = iroot[i + 3] * iprod;\n       \
    \     prod *= iroot[i + 3];\n            iprod *= root[i + 3];\n         }\n \
    \     }\n   }\n};\n\nvoid butterfly(vector<mm>& a) {\n   int n = int(a.size());\n\
    \   int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mm> info;\n\
    \n   int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n   while\
    \ (len < h) {\n      if (h - len == 1) {\n         int p = 1 << (h - len - 1);\n\
    \         mm rot = 1;\n         for (int s = 0; s < (1 << len); s++) {\n     \
    \       int offset = s << (h - len);\n            for (int i = 0; i < p; i++)\
    \ {\n               auto l = a[i + offset];\n               auto r = a[i + offset\
    \ + p] * rot;\n               a[i + offset] = l + r;\n               a[i + offset\
    \ + p] = l - r;\n            }\n            if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~(uint)(s))];\n\
    \         }\n         len++;\n      } else {\n         int p = 1 << (h - len -\
    \ 2);\n         mm rot = 1, imag = info.root[2];\n         for (int s = 0; s <\
    \ (1 << len); s++) {\n            mm rot2 = rot * rot;\n            mm rot3 =\
    \ rot2 * rot;\n            int offset = s << (h - len);\n            for (int\
    \ i = 0; i < p; i++) {\n               auto mod2 = 1ULL * mod * mod;\n       \
    \        auto a0 = 1ULL * a[i + offset].val();\n               auto a1 = 1ULL\
    \ * a[i + offset + p].val() * rot.val();\n               auto a2 = 1ULL * a[i\
    \ + offset + 2 * p].val() * rot2.val();\n               auto a3 = 1ULL * a[i +\
    \ offset + 3 * p].val() * rot3.val();\n               auto a1na3imag = 1ULL *\
    \ mm(a1 + mod2 - a3).val() * imag.val();\n               auto na2 = mod2 - a2;\n\
    \               a[i + offset] = a0 + a2 + a1 + a3;\n               a[i + offset\
    \ + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n               a[i + offset +\
    \ 2 * p] = a0 + na2 + a1na3imag;\n               a[i + offset + 3 * p] = a0 +\
    \ na2 + (mod2 - a1na3imag);\n            }\n            if (s + 1 != (1 << len))\
    \ rot *= info.rate3[countr_zero(~(uint)(s))];\n         }\n         len += 2;\n\
    \      }\n   }\n}\n\nvoid butterfly_inv(vector<mm>& a) {\n   int n = int(a.size());\n\
    \   int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mm> info;\n\
    \n   int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n   while\
    \ (len) {\n      if (len == 1) {\n         int p = 1 << (h - len);\n         mm\
    \ irot = 1;\n         for (int s = 0; s < (1 << (len - 1)); s++) {\n         \
    \   int offset = s << (h - len + 1);\n            for (int i = 0; i < p; i++)\
    \ {\n               auto l = a[i + offset];\n               auto r = a[i + offset\
    \ + p];\n               a[i + offset] = l + r;\n               a[i + offset +\
    \ p] = (ull)(mod + l.val() - r.val()) * irot.val();\n               ;\n      \
    \      }\n            if (s + 1 != (1 << (len - 1))) irot *= info.irate2[countr_zero(~(uint)(s))];\n\
    \         }\n         len--;\n      } else {\n         int p = 1 << (h - len);\n\
    \         mm irot = 1, iimag = info.iroot[2];\n         for (int s = 0; s < (1\
    \ << (len - 2)); s++) {\n            mm irot2 = irot * irot;\n            mm irot3\
    \ = irot2 * irot;\n            int offset = s << (h - len + 2);\n            for\
    \ (int i = 0; i < p; i++) {\n               auto a0 = 1ULL * a[i + offset + 0\
    \ * p].val();\n               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n\
    \               auto a2 = 1ULL * a[i + offset + 2 * p].val();\n              \
    \ auto a3 = 1ULL * a[i + offset + 3 * p].val();\n\n               auto a2na3iimag\
    \ = 1ULL * mm((mod + a2 - a3) * iimag.val()).val();\n\n               a[i + offset]\
    \ = a0 + a1 + a2 + a3;\n               a[i + offset + 1 * p] = (a0 + (mod - a1)\
    \ + a2na3iimag) * irot.val();\n               a[i + offset + 2 * p] = (a0 + a1\
    \ + (mod - a2) + (mod - a3)) * irot2.val();\n               a[i + offset + 3 *\
    \ p] = (a0 + (mod - a1) + (mod - a2na3iimag)) * irot3.val();\n            }\n\
    \            if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~(uint)(s))];\n\
    \         }\n         len -= 2;\n      }\n   }\n}\n\nvector<mm> convolution_naive(const\
    \ vector<mm>& a, const vector<mm>& b) {\n   int n = int(a.size()), m = int(b.size());\n\
    \   vector<mm> ans(n + m - 1);\n   if (n < m) {\n      for (int j = 0; j < m;\
    \ j++) {\n         for (int i = 0; i < n; i++) { ans[i + j] += a[i] * b[j]; }\n\
    \      }\n   } else {\n      for (int i = 0; i < n; i++) {\n         for (int\
    \ j = 0; j < m; j++) { ans[i + j] += a[i] * b[j]; }\n      }\n   }\n   return\
    \ ans;\n}\n\nvector<mm> convolution_fft(vector<mm> a, vector<mm> b) {\n   int\
    \ n = int(a.size()), m = int(b.size());\n   int z = (int)internal::bit_ceil((uint)(n\
    \ + m - 1));\n   a.resize(z);\n   internal::butterfly(a);\n   b.resize(z);\n \
    \  internal::butterfly(b);\n   for (int i = 0; i < z; i++) { a[i] *= b[i]; }\n\
    \   internal::butterfly_inv(a);\n   a.resize(n + m - 1);\n   mm iz = mm(z).inv();\n\
    \   for (int i = 0; i < n + m - 1; i++) a[i] *= iz;\n   return a;\n}\n\nvector<mm>\
    \ convolution(const vector<mm>& a, const vector<mm>& b) {\n   int n = int(a.size()),\
    \ m = int(b.size());\n   if (!n || !m) return {};\n\n   int z = (int)internal::bit_ceil((uint)(n\
    \ + m - 1));\n   assert((mod - 1) % z == 0);\n\n   if (min(n, m) <= 60) return\
    \ convolution_naive(a, b);\n   return internal::convolution_fft(a, b);\n}\n"
  dependsOn:
  - test/template.hpp
  isVerificationFile: false
  path: src/FPS/FFT.hpp
  requiredBy: []
  timestamp: '2024-02-15 00:53:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FPS/FFT.hpp
layout: document
redirect_from:
- /library/src/FPS/FFT.hpp
- /library/src/FPS/FFT.hpp.html
title: src/FPS/FFT.hpp
---
