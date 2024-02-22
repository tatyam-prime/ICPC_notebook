struct BIT {
   vector<ll> a;
   BIT(ll n) : a(n + 1) {}
   void add(ll p, ll x) {  // A[p] += x
      p++;
      while(p < sz(a)) {
         a[p] += x;
         p += p & -p;
      }
   }
   ll sum(ll r) {
      ll s = 0;
      while(r > 0) {
         s += a[r];
         r -= r & -r;
      }
      return s;
   }
   ll sum(ll l, ll r) {  // sum of A[l, r)
      return sum(r) - sum(l);
   }
};
