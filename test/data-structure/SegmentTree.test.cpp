#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "test/template.hpp"
using u64 = uint64_t;
#include "src/data-structure/SegmentTree.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   int N, Q;
   cin >> N >> Q;
   vector<ll> A(N);
   rep(i, 0, N) cin >> A[i];
   SegmentTree<ll> seg(A, 0, [](ll a, ll b) { return a + b; });
   rep(q, 0, Q) {
      int type;
      cin >> type;
      if(type == 0) {
         ll p, x;
         cin >> p >> x;
         seg.set(p, seg.get(p) + x);
      } else {
         int l, r;
         cin >> l >> r;
         cout << seg.prod(l, r) << '\n';
      }
   }
   cout << flush;
}
