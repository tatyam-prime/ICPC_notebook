#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "test/template.hpp"
#include "src/string/Zalgorithm.hpp"

int main() {
   cin.tie(0)->sync_with_stdio(0);
   string S;
   cin >> S;
   auto z = Z(S);
   rep(i, 0, sz(S)) cout << z[i] << " \n"[i + 1 == sz(S)];
}
