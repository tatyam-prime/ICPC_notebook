#include "test/template.hpp"

constexpr pair<ll, ll> inv_gcd(ll a, ll b) {
   a = safe_mod(a, b);
   if (a == 0) return {b, 0};

   ll s = b, t = a;
   ll m0 = 0, m1 = 1;

   while (t) {
      ll u = s / t;
      s -= t * u;
      m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

      auto tmp = s;
      s = t;
      t = tmp;
      tmp = m0;
      m0 = m1;
      m1 = tmp;
   }
   if (m0 < 0) m0 += b / s;
   return {s, m0};
}

using ull = uint64_t;
ull floor_sum_unsigned(ull n, ull m, ull a, ull b) {
   ull ans = 0;
   while (true) {
      if (a >= m) {
         ans += n * (n - 1) / 2 * (a / m);
         a %= m;
      }
      if (b >= m) {
         ans += n * (b / m);
         b %= m;
      }

      ull y_max = a * n + b;
      if (y_max < m) break;
      n = (ull)(y_max / m);
      b = (ull)(y_max % m);
      swap(m, a);
   }
   return ans;
}

struct fft_info {
   static constexpr int rank2 = countr_zero_constexpr(mod - 1);
   array<mm, rank2 + 1> root;   // root[i]^(2^i) == 1
   array<mm, rank2 + 1> iroot;  // root[i] * iroot[i] == 1

   array<mm, max(0, rank2 - 2 + 1)> rate2;
   array<mm, max(0, rank2 - 2 + 1)> irate2;

   array<mm, max(0, rank2 - 3 + 1)> rate3;
   array<mm, max(0, rank2 - 3 + 1)> irate3;

   fft_info() {
      root[rank2] = mm(g).pow((mod - 1) >> rank2);
      iroot[rank2] = root[rank2].inv();
      for (int i = rank2 - 1; i >= 0; i--) {
         root[i] = root[i + 1] * root[i + 1];
         iroot[i] = iroot[i + 1] * iroot[i + 1];
      }

      {
         mm prod = 1, iprod = 1;
         for (int i = 0; i <= rank2 - 2; i++) {
            rate2[i] = root[i + 2] * prod;
            irate2[i] = iroot[i + 2] * iprod;
            prod *= iroot[i + 2];
            iprod *= root[i + 2];
         }
      }
      {
         mm prod = 1, iprod = 1;
         for (int i = 0; i <= rank2 - 3; i++) {
            rate3[i] = root[i + 3] * prod;
            irate3[i] = iroot[i + 3] * iprod;
            prod *= iroot[i + 3];
            iprod *= root[i + 3];
         }
      }
   }
};

void butterfly(vector<mm>& a) {
   int n = int(a.size());
   int h = internal::countr_zero((uint)n);

   static const fft_info<mm> info;

   int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
   while (len < h) {
      if (h - len == 1) {
         int p = 1 << (h - len - 1);
         mm rot = 1;
         for (int s = 0; s < (1 << len); s++) {
            int offset = s << (h - len);
            for (int i = 0; i < p; i++) {
               auto l = a[i + offset];
               auto r = a[i + offset + p] * rot;
               a[i + offset] = l + r;
               a[i + offset + p] = l - r;
            }
            if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~(uint)(s))];
         }
         len++;
      } else {
         int p = 1 << (h - len - 2);
         mm rot = 1, imag = info.root[2];
         for (int s = 0; s < (1 << len); s++) {
            mm rot2 = rot * rot;
            mm rot3 = rot2 * rot;
            int offset = s << (h - len);
            for (int i = 0; i < p; i++) {
               auto mod2 = 1ULL * mod * mod;
               auto a0 = 1ULL * a[i + offset].val();
               auto a1 = 1ULL * a[i + offset + p].val() * rot.val();
               auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();
               auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();
               auto a1na3imag = 1ULL * mm(a1 + mod2 - a3).val() * imag.val();
               auto na2 = mod2 - a2;
               a[i + offset] = a0 + a2 + a1 + a3;
               a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));
               a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
               a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);
            }
            if (s + 1 != (1 << len)) rot *= info.rate3[countr_zero(~(uint)(s))];
         }
         len += 2;
      }
   }
}

void butterfly_inv(vector<mm>& a) {
   int n = int(a.size());
   int h = internal::countr_zero((uint)n);

   static const fft_info<mm> info;

   int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
   while (len) {
      if (len == 1) {
         int p = 1 << (h - len);
         mm irot = 1;
         for (int s = 0; s < (1 << (len - 1)); s++) {
            int offset = s << (h - len + 1);
            for (int i = 0; i < p; i++) {
               auto l = a[i + offset];
               auto r = a[i + offset + p];
               a[i + offset] = l + r;
               a[i + offset + p] = (ull)(mod + l.val() - r.val()) * irot.val();
               ;
            }
            if (s + 1 != (1 << (len - 1))) irot *= info.irate2[countr_zero(~(uint)(s))];
         }
         len--;
      } else {
         int p = 1 << (h - len);
         mm irot = 1, iimag = info.iroot[2];
         for (int s = 0; s < (1 << (len - 2)); s++) {
            mm irot2 = irot * irot;
            mm irot3 = irot2 * irot;
            int offset = s << (h - len + 2);
            for (int i = 0; i < p; i++) {
               auto a0 = 1ULL * a[i + offset + 0 * p].val();
               auto a1 = 1ULL * a[i + offset + 1 * p].val();
               auto a2 = 1ULL * a[i + offset + 2 * p].val();
               auto a3 = 1ULL * a[i + offset + 3 * p].val();

               auto a2na3iimag = 1ULL * mm((mod + a2 - a3) * iimag.val()).val();

               a[i + offset] = a0 + a1 + a2 + a3;
               a[i + offset + 1 * p] = (a0 + (mod - a1) + a2na3iimag) * irot.val();
               a[i + offset + 2 * p] = (a0 + a1 + (mod - a2) + (mod - a3)) * irot2.val();
               a[i + offset + 3 * p] = (a0 + (mod - a1) + (mod - a2na3iimag)) * irot3.val();
            }
            if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~(uint)(s))];
         }
         len -= 2;
      }
   }
}

vector<mm> convolution_naive(const vector<mm>& a, const vector<mm>& b) {
   int n = int(a.size()), m = int(b.size());
   vector<mm> ans(n + m - 1);
   if (n < m) {
      for (int j = 0; j < m; j++) {
         for (int i = 0; i < n; i++) { ans[i + j] += a[i] * b[j]; }
      }
   } else {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) { ans[i + j] += a[i] * b[j]; }
      }
   }
   return ans;
}

vector<mm> convolution_fft(vector<mm> a, vector<mm> b) {
   int n = int(a.size()), m = int(b.size());
   int z = (int)internal::bit_ceil((uint)(n + m - 1));
   a.resize(z);
   internal::butterfly(a);
   b.resize(z);
   internal::butterfly(b);
   for (int i = 0; i < z; i++) { a[i] *= b[i]; }
   internal::butterfly_inv(a);
   a.resize(n + m - 1);
   mm iz = mm(z).inv();
   for (int i = 0; i < n + m - 1; i++) a[i] *= iz;
   return a;
}

vector<mm> convolution(const vector<mm>& a, const vector<mm>& b) {
   int n = int(a.size()), m = int(b.size());
   if (!n || !m) return {};

   int z = (int)internal::bit_ceil((uint)(n + m - 1));
   assert((mod - 1) % z == 0);

   if (min(n, m) <= 60) return convolution_naive(a, b);
   return internal::convolution_fft(a, b);
}
