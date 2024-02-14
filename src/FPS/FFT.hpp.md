---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/FPS/FFT.hpp\"\nconstexpr ll pow_mod_constexpr(ll x,\
    \ ll n, int m) {\n   if (m == 1) return 0;\n   uint _m = (uint)(m);\n   ull r\
    \ = 1;\n   ull y = x % m;\n   while (n) {\n      if (n & 1) r = (r * y) % _m;\n\
    \      y = (y * y) % _m;\n      n >>= 1;\n   }\n   return r;\n}\n\nconstexpr bool\
    \ is_prime_constexpr(int n) {\n   if (n <= 1) return false;\n   if (n == 2 ||\
    \ n == 7 || n == 61) return true;\n   if (n % 2 == 0) return false;\n   ll d =\
    \ n - 1;\n   while (d % 2 == 0) d /= 2;\n   constexpr ll bases[3] = {2, 7, 61};\n\
    \   for (ll a : bases) {\n      ll t = d;\n      ll y = pow_mod_constexpr(a, t,\
    \ n);\n      while (t != n - 1 && y != 1 && y != n - 1) {\n         y = y * y\
    \ % n;\n         t <<= 1;\n      }\n      if (y != n - 1 && t % 2 == 0) { return\
    \ false; }\n   }\n   return true;\n}\ntemplate<int n> constexpr bool is_prime\
    \ = is_prime_constexpr(n);\n\nconstexpr pair<ll, ll> inv_gcd(ll a, ll b) {\n \
    \  a = safe_mod(a, b);\n   if (a == 0) return {b, 0};\n\n   ll s = b, t = a;\n\
    \   ll m0 = 0, m1 = 1;\n\n   while (t) {\n      ll u = s / t;\n      s -= t *\
    \ u;\n      m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n      auto tmp = s;\n\
    \      s = t;\n      t = tmp;\n      tmp = m0;\n      m0 = m1;\n      m1 = tmp;\n\
    \   }\n   if (m0 < 0) m0 += b / s;\n   return {s, m0};\n}\n\null floor_sum_unsigned(ull\
    \ n, ull m, ull a, ull b) {\n   ull ans = 0;\n   while (true) {\n      if (a >=\
    \ m) {\n         ans += n * (n - 1) / 2 * (a / m);\n         a %= m;\n      }\n\
    \      if (b >= m) {\n         ans += n * (b / m);\n         b %= m;\n      }\n\
    \n      ull y_max = a * n + b;\n      if (y_max < m) break;\n      n = (ull)(y_max\
    \ / m);\n      b = (ull)(y_max % m);\n      swap(m, a);\n   }\n   return ans;\n\
    }\n\ntemplate<class mint, int g = internal::primitive_root<mint::mod()>, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n   static constexpr int rank2 = countr_zero_constexpr(mint::mod()\
    \ - 1);\n   array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n   array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n   array<mint, max(0, rank2\
    \ - 2 + 1)> rate2;\n   array<mint, max(0, rank2 - 2 + 1)> irate2;\n\n   array<mint,\
    \ max(0, rank2 - 3 + 1)> rate3;\n   array<mint, max(0, rank2 - 3 + 1)> irate3;\n\
    \n   fft_info() {\n      root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n\
    \      iroot[rank2] = root[rank2].inv();\n      for (int i = rank2 - 1; i >= 0;\
    \ i--) {\n         root[i] = root[i + 1] * root[i + 1];\n         iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n      }\n\n      {\n         mint prod = 1, iprod = 1;\n\
    \         for (int i = 0; i <= rank2 - 2; i++) {\n            rate2[i] = root[i\
    \ + 2] * prod;\n            irate2[i] = iroot[i + 2] * iprod;\n            prod\
    \ *= iroot[i + 2];\n            iprod *= root[i + 2];\n         }\n      }\n \
    \     {\n         mint prod = 1, iprod = 1;\n         for (int i = 0; i <= rank2\
    \ - 3; i++) {\n            rate3[i] = root[i + 3] * prod;\n            irate3[i]\
    \ = iroot[i + 3] * iprod;\n            prod *= iroot[i + 3];\n            iprod\
    \ *= root[i + 3];\n         }\n      }\n   }\n};\n\ntemplate<class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr> void butterfly(vector<mint>& a) {\n   int n = int(a.size());\n  \
    \ int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mint> info;\n\
    \n   int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n   while\
    \ (len < h) {\n      if (h - len == 1) {\n         int p = 1 << (h - len - 1);\n\
    \         mint rot = 1;\n         for (int s = 0; s < (1 << len); s++) {\n   \
    \         int offset = s << (h - len);\n            for (int i = 0; i < p; i++)\
    \ {\n               auto l = a[i + offset];\n               auto r = a[i + offset\
    \ + p] * rot;\n               a[i + offset] = l + r;\n               a[i + offset\
    \ + p] = l - r;\n            }\n            if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~(uint)(s))];\n\
    \         }\n         len++;\n      } else {\n         int p = 1 << (h - len -\
    \ 2);\n         mint rot = 1, imag = info.root[2];\n         for (int s = 0; s\
    \ < (1 << len); s++) {\n            mint rot2 = rot * rot;\n            mint rot3\
    \ = rot2 * rot;\n            int offset = s << (h - len);\n            for (int\
    \ i = 0; i < p; i++) {\n               auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \               auto a0 = 1ULL * a[i + offset].val();\n               auto a1\
    \ = 1ULL * a[i + offset + p].val() * rot.val();\n               auto a2 = 1ULL\
    \ * a[i + offset + 2 * p].val() * rot2.val();\n               auto a3 = 1ULL *\
    \ a[i + offset + 3 * p].val() * rot3.val();\n               auto a1na3imag = 1ULL\
    \ * mint(a1 + mod2 - a3).val() * imag.val();\n               auto na2 = mod2 -\
    \ a2;\n               a[i + offset] = a0 + a2 + a1 + a3;\n               a[i +\
    \ offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n               a[i + offset\
    \ + 2 * p] = a0 + na2 + a1na3imag;\n               a[i + offset + 3 * p] = a0\
    \ + na2 + (mod2 - a1na3imag);\n            }\n            if (s + 1 != (1 << len))\
    \ rot *= info.rate3[countr_zero(~(uint)(s))];\n         }\n         len += 2;\n\
    \      }\n   }\n}\n\ntemplate<class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr> void butterfly_inv(vector<mint>& a) {\n   int n = int(a.size());\n\
    \   int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mint>\
    \ info;\n\n   int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \   while (len) {\n      if (len == 1) {\n         int p = 1 << (h - len);\n \
    \        mint irot = 1;\n         for (int s = 0; s < (1 << (len - 1)); s++) {\n\
    \            int offset = s << (h - len + 1);\n            for (int i = 0; i <\
    \ p; i++) {\n               auto l = a[i + offset];\n               auto r = a[i\
    \ + offset + p];\n               a[i + offset] = l + r;\n               a[i +\
    \ offset + p] = (ull)(mint::mod() + l.val() - r.val()) * irot.val();\n       \
    \        ;\n            }\n            if (s + 1 != (1 << (len - 1))) irot *=\
    \ info.irate2[countr_zero(~(uint)(s))];\n         }\n         len--;\n      }\
    \ else {\n         int p = 1 << (h - len);\n         mint irot = 1, iimag = info.iroot[2];\n\
    \         for (int s = 0; s < (1 << (len - 2)); s++) {\n            mint irot2\
    \ = irot * irot;\n            mint irot3 = irot2 * irot;\n            int offset\
    \ = s << (h - len + 2);\n            for (int i = 0; i < p; i++) {\n         \
    \      auto a0 = 1ULL * a[i + offset + 0 * p].val();\n               auto a1 =\
    \ 1ULL * a[i + offset + 1 * p].val();\n               auto a2 = 1ULL * a[i + offset\
    \ + 2 * p].val();\n               auto a3 = 1ULL * a[i + offset + 3 * p].val();\n\
    \n               auto a2na3iimag = 1ULL * mint((mint::mod() + a2 - a3) * iimag.val()).val();\n\
    \n               a[i + offset] = a0 + a1 + a2 + a3;\n               a[i + offset\
    \ + 1 * p] = (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n          \
    \     a[i + offset + 2 * p] = (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3))\
    \ * irot2.val();\n               a[i + offset + 3 * p] = (a0 + (mint::mod() -\
    \ a1) + (mint::mod() - a2na3iimag)) * irot3.val();\n            }\n          \
    \  if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~(uint)(s))];\n\
    \         }\n         len -= 2;\n      }\n   }\n}\n\ntemplate<class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvector<mint> convolution_naive(const vector<mint>& a, const vector<mint>&\
    \ b) {\n   int n = int(a.size()), m = int(b.size());\n   vector<mint> ans(n +\
    \ m - 1);\n   if (n < m) {\n      for (int j = 0; j < m; j++) {\n         for\
    \ (int i = 0; i < n; i++) { ans[i + j] += a[i] * b[j]; }\n      }\n   } else {\n\
    \      for (int i = 0; i < n; i++) {\n         for (int j = 0; j < m; j++) { ans[i\
    \ + j] += a[i] * b[j]; }\n      }\n   }\n   return ans;\n}\n\ntemplate<class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nvector<mint> convolution_fft(vector<mint>\
    \ a, vector<mint> b) {\n   int n = int(a.size()), m = int(b.size());\n   int z\
    \ = (int)internal::bit_ceil((uint)(n + m - 1));\n   a.resize(z);\n   internal::butterfly(a);\n\
    \   b.resize(z);\n   internal::butterfly(b);\n   for (int i = 0; i < z; i++) {\
    \ a[i] *= b[i]; }\n   internal::butterfly_inv(a);\n   a.resize(n + m - 1);\n \
    \  mint iz = mint(z).inv();\n   for (int i = 0; i < n + m - 1; i++) a[i] *= iz;\n\
    \   return a;\n}\n\ntemplate<class mint, internal::is_static_modint_t<mint>* =\
    \ nullptr>\nvector<mint> convolution(const vector<mint>& a, const vector<mint>&\
    \ b) {\n   int n = int(a.size()), m = int(b.size());\n   if (!n || !m) return\
    \ {};\n\n   int z = (int)internal::bit_ceil((uint)(n + m - 1));\n   assert((mint::mod()\
    \ - 1) % z == 0);\n\n   if (min(n, m) <= 60) return convolution_naive(a, b);\n\
    \   return internal::convolution_fft(a, b);\n}\n\nvector<ll> convolution_ll(const\
    \ vector<ll>& a, const vector<ll>& b) {\n   int n = int(a.size()), m = int(b.size());\n\
    \   if (!n || !m) return {};\n\n   static constexpr ull MOD1 = 754974721;  //\
    \ 2^24\n   static constexpr ull MOD2 = 167772161;  // 2^25\n   static constexpr\
    \ ull MOD3 = 469762049;  // 2^26\n   static constexpr ull M2M3 = MOD2 * MOD3;\n\
    \   static constexpr ull M1M3 = MOD1 * MOD3;\n   static constexpr ull M1M2 = MOD1\
    \ * MOD2;\n   static constexpr ull M1M2M3 = MOD1 * MOD2 * MOD3;\n\n   static constexpr\
    \ ull i1 = internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n   static constexpr ull\
    \ i2 = internal::inv_gcd(MOD1 * MOD3, MOD2).second;\n   static constexpr ull i3\
    \ = internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n   static constexpr int MAX_AB_BIT\
    \ = 24;\n   static_assert(MOD1 % (1ull << MAX_AB_BIT) == 1, \"MOD1 isn't enough\
    \ to support an array length of 2^24.\");\n   static_assert(MOD2 % (1ull << MAX_AB_BIT)\
    \ == 1, \"MOD2 isn't enough to support an array length of 2^24.\");\n   static_assert(MOD3\
    \ % (1ull << MAX_AB_BIT) == 1, \"MOD3 isn't enough to support an array length\
    \ of 2^24.\");\n   assert(n + m - 1 <= (1 << MAX_AB_BIT));\n\n   auto c1 = convolution<MOD1>(a,\
    \ b);\n   auto c2 = convolution<MOD2>(a, b);\n   auto c3 = convolution<MOD3>(a,\
    \ b);\n\n   vector<ll> c(n + m - 1);\n   for (int i = 0; i < n + m - 1; i++) {\n\
    \      ull x = 0;\n      x += (c1[i] * i1) % MOD1 * M2M3;\n      x += (c2[i] *\
    \ i2) % MOD2 * M1M3;\n      x += (c3[i] * i3) % MOD3 * M1M2;\n      ll diff =\
    \ c1[i] - internal::safe_mod((ll)(x), (ll)(MOD1));\n      if (diff < 0) diff +=\
    \ MOD1;\n      static constexpr ull offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 *\
    \ M1M2M3};\n      x -= offset[diff % 5];\n      c[i] = x;\n   }\n\n   return c;\n\
    }\n"
  code: "constexpr ll pow_mod_constexpr(ll x, ll n, int m) {\n   if (m == 1) return\
    \ 0;\n   uint _m = (uint)(m);\n   ull r = 1;\n   ull y = x % m;\n   while (n)\
    \ {\n      if (n & 1) r = (r * y) % _m;\n      y = (y * y) % _m;\n      n >>=\
    \ 1;\n   }\n   return r;\n}\n\nconstexpr bool is_prime_constexpr(int n) {\n  \
    \ if (n <= 1) return false;\n   if (n == 2 || n == 7 || n == 61) return true;\n\
    \   if (n % 2 == 0) return false;\n   ll d = n - 1;\n   while (d % 2 == 0) d /=\
    \ 2;\n   constexpr ll bases[3] = {2, 7, 61};\n   for (ll a : bases) {\n      ll\
    \ t = d;\n      ll y = pow_mod_constexpr(a, t, n);\n      while (t != n - 1 &&\
    \ y != 1 && y != n - 1) {\n         y = y * y % n;\n         t <<= 1;\n      }\n\
    \      if (y != n - 1 && t % 2 == 0) { return false; }\n   }\n   return true;\n\
    }\ntemplate<int n> constexpr bool is_prime = is_prime_constexpr(n);\n\nconstexpr\
    \ pair<ll, ll> inv_gcd(ll a, ll b) {\n   a = safe_mod(a, b);\n   if (a == 0) return\
    \ {b, 0};\n\n   ll s = b, t = a;\n   ll m0 = 0, m1 = 1;\n\n   while (t) {\n  \
    \    ll u = s / t;\n      s -= t * u;\n      m0 -= m1 * u;  // |m1 * u| <= |m1|\
    \ * s <= b\n\n      auto tmp = s;\n      s = t;\n      t = tmp;\n      tmp = m0;\n\
    \      m0 = m1;\n      m1 = tmp;\n   }\n   if (m0 < 0) m0 += b / s;\n   return\
    \ {s, m0};\n}\n\null floor_sum_unsigned(ull n, ull m, ull a, ull b) {\n   ull\
    \ ans = 0;\n   while (true) {\n      if (a >= m) {\n         ans += n * (n - 1)\
    \ / 2 * (a / m);\n         a %= m;\n      }\n      if (b >= m) {\n         ans\
    \ += n * (b / m);\n         b %= m;\n      }\n\n      ull y_max = a * n + b;\n\
    \      if (y_max < m) break;\n      n = (ull)(y_max / m);\n      b = (ull)(y_max\
    \ % m);\n      swap(m, a);\n   }\n   return ans;\n}\n\ntemplate<class mint, int\
    \ g = internal::primitive_root<mint::mod()>, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n   static constexpr int rank2 = countr_zero_constexpr(mint::mod()\
    \ - 1);\n   array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n   array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n   array<mint, max(0, rank2\
    \ - 2 + 1)> rate2;\n   array<mint, max(0, rank2 - 2 + 1)> irate2;\n\n   array<mint,\
    \ max(0, rank2 - 3 + 1)> rate3;\n   array<mint, max(0, rank2 - 3 + 1)> irate3;\n\
    \n   fft_info() {\n      root[rank2] = mint(g).pow((mint::mod() - 1) >> rank2);\n\
    \      iroot[rank2] = root[rank2].inv();\n      for (int i = rank2 - 1; i >= 0;\
    \ i--) {\n         root[i] = root[i + 1] * root[i + 1];\n         iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n      }\n\n      {\n         mint prod = 1, iprod = 1;\n\
    \         for (int i = 0; i <= rank2 - 2; i++) {\n            rate2[i] = root[i\
    \ + 2] * prod;\n            irate2[i] = iroot[i + 2] * iprod;\n            prod\
    \ *= iroot[i + 2];\n            iprod *= root[i + 2];\n         }\n      }\n \
    \     {\n         mint prod = 1, iprod = 1;\n         for (int i = 0; i <= rank2\
    \ - 3; i++) {\n            rate3[i] = root[i + 3] * prod;\n            irate3[i]\
    \ = iroot[i + 3] * iprod;\n            prod *= iroot[i + 3];\n            iprod\
    \ *= root[i + 3];\n         }\n      }\n   }\n};\n\ntemplate<class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr> void butterfly(vector<mint>& a) {\n   int n = int(a.size());\n  \
    \ int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mint> info;\n\
    \n   int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n   while\
    \ (len < h) {\n      if (h - len == 1) {\n         int p = 1 << (h - len - 1);\n\
    \         mint rot = 1;\n         for (int s = 0; s < (1 << len); s++) {\n   \
    \         int offset = s << (h - len);\n            for (int i = 0; i < p; i++)\
    \ {\n               auto l = a[i + offset];\n               auto r = a[i + offset\
    \ + p] * rot;\n               a[i + offset] = l + r;\n               a[i + offset\
    \ + p] = l - r;\n            }\n            if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~(uint)(s))];\n\
    \         }\n         len++;\n      } else {\n         int p = 1 << (h - len -\
    \ 2);\n         mint rot = 1, imag = info.root[2];\n         for (int s = 0; s\
    \ < (1 << len); s++) {\n            mint rot2 = rot * rot;\n            mint rot3\
    \ = rot2 * rot;\n            int offset = s << (h - len);\n            for (int\
    \ i = 0; i < p; i++) {\n               auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \               auto a0 = 1ULL * a[i + offset].val();\n               auto a1\
    \ = 1ULL * a[i + offset + p].val() * rot.val();\n               auto a2 = 1ULL\
    \ * a[i + offset + 2 * p].val() * rot2.val();\n               auto a3 = 1ULL *\
    \ a[i + offset + 3 * p].val() * rot3.val();\n               auto a1na3imag = 1ULL\
    \ * mint(a1 + mod2 - a3).val() * imag.val();\n               auto na2 = mod2 -\
    \ a2;\n               a[i + offset] = a0 + a2 + a1 + a3;\n               a[i +\
    \ offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n               a[i + offset\
    \ + 2 * p] = a0 + na2 + a1na3imag;\n               a[i + offset + 3 * p] = a0\
    \ + na2 + (mod2 - a1na3imag);\n            }\n            if (s + 1 != (1 << len))\
    \ rot *= info.rate3[countr_zero(~(uint)(s))];\n         }\n         len += 2;\n\
    \      }\n   }\n}\n\ntemplate<class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr> void butterfly_inv(vector<mint>& a) {\n   int n = int(a.size());\n\
    \   int h = internal::countr_zero((uint)n);\n\n   static const fft_info<mint>\
    \ info;\n\n   int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \   while (len) {\n      if (len == 1) {\n         int p = 1 << (h - len);\n \
    \        mint irot = 1;\n         for (int s = 0; s < (1 << (len - 1)); s++) {\n\
    \            int offset = s << (h - len + 1);\n            for (int i = 0; i <\
    \ p; i++) {\n               auto l = a[i + offset];\n               auto r = a[i\
    \ + offset + p];\n               a[i + offset] = l + r;\n               a[i +\
    \ offset + p] = (ull)(mint::mod() + l.val() - r.val()) * irot.val();\n       \
    \        ;\n            }\n            if (s + 1 != (1 << (len - 1))) irot *=\
    \ info.irate2[countr_zero(~(uint)(s))];\n         }\n         len--;\n      }\
    \ else {\n         int p = 1 << (h - len);\n         mint irot = 1, iimag = info.iroot[2];\n\
    \         for (int s = 0; s < (1 << (len - 2)); s++) {\n            mint irot2\
    \ = irot * irot;\n            mint irot3 = irot2 * irot;\n            int offset\
    \ = s << (h - len + 2);\n            for (int i = 0; i < p; i++) {\n         \
    \      auto a0 = 1ULL * a[i + offset + 0 * p].val();\n               auto a1 =\
    \ 1ULL * a[i + offset + 1 * p].val();\n               auto a2 = 1ULL * a[i + offset\
    \ + 2 * p].val();\n               auto a3 = 1ULL * a[i + offset + 3 * p].val();\n\
    \n               auto a2na3iimag = 1ULL * mint((mint::mod() + a2 - a3) * iimag.val()).val();\n\
    \n               a[i + offset] = a0 + a1 + a2 + a3;\n               a[i + offset\
    \ + 1 * p] = (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n          \
    \     a[i + offset + 2 * p] = (a0 + a1 + (mint::mod() - a2) + (mint::mod() - a3))\
    \ * irot2.val();\n               a[i + offset + 3 * p] = (a0 + (mint::mod() -\
    \ a1) + (mint::mod() - a2na3iimag)) * irot3.val();\n            }\n          \
    \  if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~(uint)(s))];\n\
    \         }\n         len -= 2;\n      }\n   }\n}\n\ntemplate<class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvector<mint> convolution_naive(const vector<mint>& a, const vector<mint>&\
    \ b) {\n   int n = int(a.size()), m = int(b.size());\n   vector<mint> ans(n +\
    \ m - 1);\n   if (n < m) {\n      for (int j = 0; j < m; j++) {\n         for\
    \ (int i = 0; i < n; i++) { ans[i + j] += a[i] * b[j]; }\n      }\n   } else {\n\
    \      for (int i = 0; i < n; i++) {\n         for (int j = 0; j < m; j++) { ans[i\
    \ + j] += a[i] * b[j]; }\n      }\n   }\n   return ans;\n}\n\ntemplate<class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nvector<mint> convolution_fft(vector<mint>\
    \ a, vector<mint> b) {\n   int n = int(a.size()), m = int(b.size());\n   int z\
    \ = (int)internal::bit_ceil((uint)(n + m - 1));\n   a.resize(z);\n   internal::butterfly(a);\n\
    \   b.resize(z);\n   internal::butterfly(b);\n   for (int i = 0; i < z; i++) {\
    \ a[i] *= b[i]; }\n   internal::butterfly_inv(a);\n   a.resize(n + m - 1);\n \
    \  mint iz = mint(z).inv();\n   for (int i = 0; i < n + m - 1; i++) a[i] *= iz;\n\
    \   return a;\n}\n\ntemplate<class mint, internal::is_static_modint_t<mint>* =\
    \ nullptr>\nvector<mint> convolution(const vector<mint>& a, const vector<mint>&\
    \ b) {\n   int n = int(a.size()), m = int(b.size());\n   if (!n || !m) return\
    \ {};\n\n   int z = (int)internal::bit_ceil((uint)(n + m - 1));\n   assert((mint::mod()\
    \ - 1) % z == 0);\n\n   if (min(n, m) <= 60) return convolution_naive(a, b);\n\
    \   return internal::convolution_fft(a, b);\n}\n\nvector<ll> convolution_ll(const\
    \ vector<ll>& a, const vector<ll>& b) {\n   int n = int(a.size()), m = int(b.size());\n\
    \   if (!n || !m) return {};\n\n   static constexpr ull MOD1 = 754974721;  //\
    \ 2^24\n   static constexpr ull MOD2 = 167772161;  // 2^25\n   static constexpr\
    \ ull MOD3 = 469762049;  // 2^26\n   static constexpr ull M2M3 = MOD2 * MOD3;\n\
    \   static constexpr ull M1M3 = MOD1 * MOD3;\n   static constexpr ull M1M2 = MOD1\
    \ * MOD2;\n   static constexpr ull M1M2M3 = MOD1 * MOD2 * MOD3;\n\n   static constexpr\
    \ ull i1 = internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n   static constexpr ull\
    \ i2 = internal::inv_gcd(MOD1 * MOD3, MOD2).second;\n   static constexpr ull i3\
    \ = internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n   static constexpr int MAX_AB_BIT\
    \ = 24;\n   static_assert(MOD1 % (1ull << MAX_AB_BIT) == 1, \"MOD1 isn't enough\
    \ to support an array length of 2^24.\");\n   static_assert(MOD2 % (1ull << MAX_AB_BIT)\
    \ == 1, \"MOD2 isn't enough to support an array length of 2^24.\");\n   static_assert(MOD3\
    \ % (1ull << MAX_AB_BIT) == 1, \"MOD3 isn't enough to support an array length\
    \ of 2^24.\");\n   assert(n + m - 1 <= (1 << MAX_AB_BIT));\n\n   auto c1 = convolution<MOD1>(a,\
    \ b);\n   auto c2 = convolution<MOD2>(a, b);\n   auto c3 = convolution<MOD3>(a,\
    \ b);\n\n   vector<ll> c(n + m - 1);\n   for (int i = 0; i < n + m - 1; i++) {\n\
    \      ull x = 0;\n      x += (c1[i] * i1) % MOD1 * M2M3;\n      x += (c2[i] *\
    \ i2) % MOD2 * M1M3;\n      x += (c3[i] * i3) % MOD3 * M1M2;\n      ll diff =\
    \ c1[i] - internal::safe_mod((ll)(x), (ll)(MOD1));\n      if (diff < 0) diff +=\
    \ MOD1;\n      static constexpr ull offset[5] = {0, 0, M1M2M3, 2 * M1M2M3, 3 *\
    \ M1M2M3};\n      x -= offset[diff % 5];\n      c[i] = x;\n   }\n\n   return c;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/FPS/FFT.hpp
  requiredBy: []
  timestamp: '2024-02-14 16:00:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FPS/FFT.hpp
layout: document
redirect_from:
- /library/src/FPS/FFT.hpp
- /library/src/FPS/FFT.hpp.html
title: src/FPS/FFT.hpp
---
