#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

namespace nyaan {

// ここにライブラリを貼る

}  // namespace nyaan
// #include "atcoder/convolution"

#include "test/template.hpp"

namespace fft1 {
#include "src/modint/modint.hpp"
#include "src/FPS/FFT.hpp"
}  // namespace fft1
namespace fft2 {
#include "src/extra/modint_fast.hpp"
#include "src/FPS/FFT_fast.hpp"
}  // namespace fft2

int main() {
   using namespace chrono;
   const ll N = 1 << 20;
   {
      vector<fft1::mm> A(N), B(N);
      rep(i, 0, N) A[i] = B[i] = i;
      auto s = system_clock::now();
      auto C = fft1::conv(A, B);
      cout << "my FFT: " << duration_cast<milliseconds>(system_clock::now() - s).count() << " ms" << endl;
   }
   {
      vector<fft2::mm> A(N), B(N);
      rep(i, 0, N) A[i] = B[i] = i;
      auto s = system_clock::now();
      auto C = fft2::conv(A, B);
      cout << "my fast FFT: " << duration_cast<milliseconds>(system_clock::now() - s).count() << " ms" << endl;
   }
   {
      vector<atcoder::modint998244353> A(N), B(N);
      rep(i, 0, N) A[i] = B[i] = i;
      auto s = system_clock::now();
      auto C = atcoder::convolution(A, B);
      cout << "ACL: " << duration_cast<milliseconds>(system_clock::now() - s).count() << " ms" << endl;
   }
   {
      const int MOD = 998244353;
      using mint = nyaan::LazyMontgomeryModInt<MOD>;
      nyaan::NTT<mint> ntt;
      vector<mint> A(N), B(N);
      rep(i, 0, N) A[i] = B[i] = i;
      auto s = system_clock::now();
      auto C = ntt.multiply(A, B);
      cout << "nyaan AVX2: " << duration_cast<milliseconds>(system_clock::now() - s).count() << " ms" << endl;
   }
}
