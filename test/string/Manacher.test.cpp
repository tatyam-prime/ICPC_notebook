#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "test/template.hpp"
#include "src/string/Manacher.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   const ll N = sz(S);
   auto [even, odd] = manacher(S);
   rep(i, 1, N * 2) cout << [&] {
      if(i % 2) return odd[i / 2] * 2 + 1;
      else return even[i / 2] * 2;
   }() << " \n"[i + 1 == N * 2];
}
