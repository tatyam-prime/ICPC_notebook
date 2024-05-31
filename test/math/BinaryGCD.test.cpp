#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
using u64 = uint64_t;
#include "src/math/BinaryGCD.hpp"

int main() {
   mt19937_64 rnd;
   rep(shift, 0, 64) {
      rep(i, 0, (ll)1e5) {
         u64 a = rnd() >> shift, b = rnd() >> shift;
         assert(gcd(a, b) == binary_gcd(a, b));
      }
   }
   puts("Hello World");
}
