// competitive-verifier: STANDALONE
#include "test/template.hpp"
#include "src/algorithm/GoldenSearch.hpp"

double argument_tolerance(double l, double r) {
   return 64 * numeric_limits<double>::epsilon() * max({1.0, abs(l), abs(r)});
}

void verify_unique_maximum(double l, double r, double expected, auto f) {
   int calls = 0;
   auto checked_f = [&](double x) {
      ++calls;
      assert(l <= x && x <= r);
      return f(x);
   };

   auto [x, fx] = golden(l, r, checked_f);
   assert(calls == 81);
   assert(l <= x && x <= r);
   assert(abs(x - expected) <= argument_tolerance(l, r));
   assert(fx == f(x));
}

int main() {
   mt19937_64 rnd(0x8f3f73b5cf1c9ade);
   auto unit = [&] { return (rnd() >> 11) * 0x1p-53; };

   rep(iteration, 0, 20000) {
      double center = (2 * unit() - 1) * 1e6;
      double width = pow(10.0, 9 * unit() - 3);
      double l = center - width / 2;
      double r = center + width / 2;
      double expected = lerp(l, r, unit());

      verify_unique_maximum(l, r, expected, [=](double x) {
         double z = (x - expected) / width;
         return -z * z;
      });
      verify_unique_maximum(l, r, expected, [=](double x) {
         double z = (x - expected) / width;
         return z < 0 ? 3 * z : -z;
      });
   }

   // Monotone functions are unimodal functions whose maximum is an endpoint.
   verify_unique_maximum(-3, 7, 7, [](double x) { return x; });
   verify_unique_maximum(-3, 7, -3, [](double x) { return -x; });

   // The interpolation must remain finite even when r - l overflows.
   double large = numeric_limits<double>::max() / 2;
   verify_unique_maximum(-large, large, 0, [=](double x) { return -abs(x / large); });

   // A non-strict maximum may be attained on an interval.
   rep(iteration, 0, 5000) {
      double l = (2 * unit() - 1) * 1e4;
      double r = l + pow(10.0, 6 * unit() - 2);
      double plateau_l = lerp(l, r, unit() * 0.4);
      double plateau_r = lerp(l, r, 0.6 + unit() * 0.4);
      double scale = r - l;
      auto f = [=](double x) {
         if(x < plateau_l) return (x - plateau_l) / scale;
         if(plateau_r < x) return (plateau_r - x) / scale;
         return 0.0;
      };

      int calls = 0;
      auto [x, fx] = golden(l, r, [&](double y) {
         ++calls;
         assert(l <= y && y <= r);
         return f(y);
      });
      assert(calls == 81);
      assert(plateau_l <= x && x <= plateau_r);
      assert(fx == 0);
   }

   int calls = 0;
   auto [x, fx] = golden(1.25, 1.25, [&](double y) {
      ++calls;
      assert(y == 1.25);
      return 42;
   });
   assert(calls == 81);
   assert(x == 1.25 && fx == 42);

   puts("Hello World");
}
