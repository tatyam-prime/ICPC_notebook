#include "test/template.hpp"

namespace fft1 {
#include "src/modint/modint.hpp"
#include "src/FPS/FFT.hpp"
}  // namespace fft1
namespace fft2 {
#include "src/extra/modint_fast.hpp"
#include "src/FPS/FFT.hpp"
}  // namespace fft2
// #include "atcoder/convolution"

int main() {
   using namespace chrono;
   const ll N = 1 << 20;
   {
      vector<fft1::mm> A(N), B(N);
      rep(i, 0, N) A[i] = B[i] = i;
      auto s = system_clock::now();
      auto C = fft1::conv(A, B);
      cout << format("my FFT: {} ms", duration_cast<milliseconds>(system_clock::now() - s).count()) << endl;
   }
   {
      vector<fft2::mm> A(N), B(N);
      rep(i, 0, N) A[i] = B[i] = i;
      auto s = system_clock::now();
      auto C = fft2::conv(A, B);
      cout << format("my FFT with fast modint: {} ms", duration_cast<milliseconds>(system_clock::now() - s).count())
           << endl;
   }
   {
      vector<atcoder::modint998244353> A(N), B(N);
      rep(i, 0, N) A[i] = B[i] = i;
      auto s = system_clock::now();
      auto C = atcoder::convolution(A, B);
      cout << format("ACL: {} ms", duration_cast<milliseconds>(system_clock::now() - s).count()) << endl;
   }
}
