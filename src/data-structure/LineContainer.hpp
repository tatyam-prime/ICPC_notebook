struct Line { 
	mutable ll a, b, p;
	bool operator<(Line o) const { return a < o.a; }
	bool operator<(ll x) const { return p < x; }
};
// for doubles, use INFINITY and div(a,b) = a/b
struct LineContainer : set<Line, less<>> {
   // floored division (b > 0)
	ll div(ll a, ll b) { return a / b - (a % b < 0); }
	bool check(auto x, auto y) {
		x->p = div(x->b - y->b, y->a - x->a);
		return x->p >= y->p;
	}
	void add(ll a, ll b) { // add line ax + b
		auto [z, f] = emplace(a, b, LLONG_MAX);
		if (z->b < b) z->b = b;
		auto y = z++, x = y;
		while (z != end() && check(y, z)) z = erase(z);
		if (x != begin() && check(--x, y)) check(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) check(x, erase(y));
	}
	ll max(ll x) {
		assert(size());
		auto l = *lower_bound(x);
		return l.a * x + l.b;
	}
};
