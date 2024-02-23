#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "test/template.hpp"
using u64 = uint64_t;
#include "src/data-structure/FastSet.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   ll N, Q;
   cin >> N >> Q;
   string S;
   cin >> S;
   FastSet s(N);
   rep(i, 0, N) if(S[i] == '1') s.set(i);
   while(Q--) {
      ll c, k;
      cin >> c >> k;
      if(c == 0) s.set(k);
      if(c == 1) s.reset(k);
      if(c == 2) cout << (s.a[0][k / B] >> (k % B) & 1) << '\n';
      if(c == 3) {
         ll ans = s.next(k - 1);
         cout << (ans == N ? -1 : ans) << '\n';
      }
      if(c == 4) cout << s.prev(k + 1) << '\n';
   }
}
