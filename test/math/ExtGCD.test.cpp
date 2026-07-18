// competitive-verifier: STANDALONE
#include "test/template.hpp"
#include "src/math/ExtGCD.hpp"

using i128 = __int128_t;
int main() {
   const auto abs = [](i128 x) { return x < 0 ? -x : x; };
   mt19937_64 rnd;
   rep(shift, 1, 64) {
      rep(i, 0, (ll)5e4) {
         ll a = rnd() >> shift;
         ll b = rnd() >> shift;
         const ll g = gcd(a, b);
         ll x, y;
         assert(extgcd(a, b, x, y) == g);
         assert((i128)a * x + (i128)b * y == g);
         if(g) {
            assert(abs((i128)x) + abs((i128)y) <= abs((i128)x - b / g) + abs((i128)y + a / g));
            assert(abs((i128)x) + abs((i128)y) <= abs((i128)x + b / g) + abs((i128)y - a / g));
         }
      }
   }
   puts("Hello World");
}
