#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
using u64 = uint64_t;
#include "src/math/FastGCD.hpp"

int main() {
   mt19937_64 rnd;
   rep(i, 0, (ll)1e7) {
      u64 a = rnd(), b = rnd();
      assert(gcd(a, b) == binary_gcd(a, b));
   }
   puts("Hello World");
}
