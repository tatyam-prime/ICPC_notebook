// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/line_add_get_min
#include "test/template.hpp"
#include "src/data-structure/LineContainer.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);

   ll N, Q;
   cin >> N >> Q;

   LineContainer cht;
   auto add = [&](ll a, ll b) { cht.add(-a, -b); };

   rep(i, 0, N) {
      ll a, b;
      cin >> a >> b;
      add(a, b);
   }

   while(Q--) {
      ll t;
      cin >> t;
      if(t == 0) {
         ll a, b;
         cin >> a >> b;
         add(a, b);
      } else {
         ll x;
         cin >> x;
         cout << -cht.max(x) << '\n';
      }
   }
}
