// returns pair{sa, lcp}
// sa 長さ n : s[sa[0]:] < s[sa[1]:] < … < s[sa[n-1]:]
// lcp 長さ n-1 : lcp[i] = LCP(s[sa[i]:], s[sa[i+1]:])
// O(n log n) time
auto SA(auto s) {  // string or vector
   // assert(s.size() >= 1);
   ll n = sz(s);
   V<ll> sa(n), r(n + 1), x(n), y(n + 1), c(n + 1);
   rep(i, 0, n) sa[i] = i;
   ranges::sort(sa, {}, [&](ll i) { return s[i]; });
   r[sa[0]] = 1;
   rep(i, 1, n) r[sa[i]] = r[sa[i - 1]] + (s[sa[i - 1]] != s[sa[i]]);
   for(ll k = 1; k < n && r[sa.back()] < n; k *= 2) {
      ll p = 0;
      rep(i, n - k, n) x[p++] = i;
      each(i, sa) if(i >= k) x[p++] = i - k;
      ranges::fill(c, 0);
      each(i, x) c[r[i]]++;
      rep(i, 0, n) c[i + 1] += c[i];
      for(ll i : x | views::reverse) sa[--c[r[i]]] = i;
      y[sa[0]] = 1;
      rep(i, 1, n) {
         ll a = sa[i - 1], b = sa[i];
         y[b] = y[a] + (r[a] != r[b] || r[min(a + k, n)] != r[min(b + k, n)]);
      }
      swap(r, y);
   }
   // if you need lcp array
   x.pop_back();
   ll h = 0;
   rep(i, 0, n) {
      ll p = r[i] - 1;
      if(p == n - 1) {
         h = 0;
         continue;
      }
      ll j = sa[p + 1];
      while(i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
      x[p] = h;
      if(h) h--;
   }
   return pair{sa, x};
}
