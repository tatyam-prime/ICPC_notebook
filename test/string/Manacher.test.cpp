#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "test/template.hpp"
#include "src/string/Manacher.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   const ll N = sz(S);
   string T(N * 2 + 1, '$');
   rep(i, 0, N) T[i * 2 + 1] = S[i];
   auto r = manacher(T);
   rep(i, 1, N * 2) {
      if(i & 1) cout << r[i] - 1 << " \n"[i + 1 == N * 2];
      else cout << r[i] - 1 << ' ';
   }
}
