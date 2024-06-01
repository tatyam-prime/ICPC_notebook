#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/math/ExtGCD.hpp"

using i128 = __int128_t;
i128 abs(i128 x) { return x < 0 ? -x : x; }
int main() {
   mt19937_64 rnd;
   rep(shift, 1, 64) {
      rep(i, 0, (ll)5e4) {
         ll a = rnd() >> shift;
         ll b = rnd() >> shift;
         const ll g = gcd(a, b);
         ll x, y;
         assert(extgcd(a, b, x, y) == g);
         assert((i128)a * x + (i128)b * y == g);
         assert(abs(x) + abs(y) <= abs((i128)x - b / g) + abs((i128)y + a / g));
         assert(abs(x) + abs(y) <= abs((i128)x + b / g) + abs((i128)y - a / g));
      }
   }
   puts("Hello World");
}
