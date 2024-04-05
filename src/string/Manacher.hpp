// returns array {even-length, odd-length} palindromes
// aaabaaa -> {01100110, 0103010}
// even-length は長さ n+1 : 両端を中心とするものが含まれていることに注意
auto manacher(string s) {
   ll n = sz(s);
   array p = {vector<ll>(n + 1), vector<ll>(n)};
   rep(z, 0, 2) for(ll i = 0, l = 0, r = 0; i < n; i++) {
      ll t = r - i + !z;
      if(i < r) p[z][i] = min(t, p[z][l + t]);
      ll L = i - p[z][i], R = i + p[z][i] - !z;
      while(L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) {
         p[z][i]++;
         L--;
         R++;
      }
      if(R > r) {
         l = L;
         r = R;
      }
   }
   return p;
}
