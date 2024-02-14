#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"
#include "src/modint/BarrettReduction.hpp"

mt19937 rnd(random_device{}());
int main() {
   rep(i, 0, 1e5) {
      const u64 mod = rnd(), a = rnd(), b = rnd(), ans1 = Barrett(mod).mul(a, b), ans2 = a * b % mod;
      if (mod == 0) continue;
      assert(ans1 == ans2);
   }
   puts("Hello World");
}
