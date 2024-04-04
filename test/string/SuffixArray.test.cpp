#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "test/template.hpp"
#include "src/string/SuffixArray.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   const ll N = sz(S);
   auto [sa, lcp] = SA(S);
   rep(i, 0, N) cout << sa[i] << " \n"[i + 1 == N];
}
