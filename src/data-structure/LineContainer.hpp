struct Line {
   mutable ll a, b, p;
   bool operator<(Line o) const { return a < o.a; }
   bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
   // (for doubles, use INF = 1/.0, div(a,b) = a/b)
   ll div(ll a, ll b) {  // floored division
      return a / b - ((a ^ b) < 0 && a % b);
   }
   bool isect(iterator x, iterator y) {
      if(y == end()) return x->p = INF, 0;
      if(x->a == y->a) x->p = x->b > y->b ? INF : -INF;
      else x->p = div(y->b - x->b, x->a - y->a);
      return x->p >= y->p;
   }
   void add(ll a, ll b) {  // add line ax + b
      auto z = insert({a, b, 0}), y = z++, x = y;
      while(isect(y, z)) z = erase(z);
      if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
      while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
   }
   ll max(ll x) {
      assert(!empty());
      auto l = *lower_bound(x);
      return l.a * x + l.b;
   }
};
