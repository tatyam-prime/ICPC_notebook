#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "test/template.hpp"
#include "src/extra/modint_fast.hpp"
#include "src/FPS/FFT_fast.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   ll N, M;
   cin >> N >> M;
   vector<mm> A(N), B(M);
   for(mm& a : A) cin >> a.x;
   for(mm& b : B) cin >> b.x;

   auto C = conv(move(A), move(B));
   rep(i, 0, sz(C)) cout << C[i].x << " \n"[i + 1 == sz(C)];
}
