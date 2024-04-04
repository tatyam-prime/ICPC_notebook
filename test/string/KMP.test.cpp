#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include "test/template.hpp"
#include "src/string/KMP.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S, T;
   cin >> S >> T;
   auto s = T + '$' + S;
   auto kmp = KMP(s);

   rep(i, sz(s) - sz(S), sz(s)) {
      if(kmp[i] == sz(T)) cout << i - sz(T) * 2 << '\n';
   }
}
