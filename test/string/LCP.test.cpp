#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "test/template.hpp"
#include "src/string/SuffixArray.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   const ll N = sz(S);
   auto [sa, lcp] = SA(S);
   cout << N * (N + 1) / 2 - accumulate(all(lcp), 0LL) << endl;
}
