#include "test/template.hpp"
#include "src/modint/modint.hpp"

mt19937 rnd(random_device{}());
int main() {
   rep(i, 0, 1e5) {
      const ll a = rnd() % mod, b = rnd() % mod;
      mm A = a, B = b, C = A * B;
      assert((A + B).x == (a + b) % mod);
      assert((A - B).x == (a - b + mod) % mod);
      assert(C.x == (a * b) % mod);
      assert((A / B.inv()).x == C.x);
      A = a;
      assert((A += B).x == (a + b) % mod);
      A = a;
      assert((A -= B).x == (a - b + mod) % mod);
      A = a;
      assert((A *= B).x == (a * b) % mod);
      A = a;
      assert((A /= B.inv()).x == C.x);
   }
}
