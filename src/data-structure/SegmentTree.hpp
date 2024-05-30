template <typename T> struct SegmentTree {

private:
  T e;
  function<T(T, T)> op;
  int n;
  vector<T> data;
#define L(i) (i << 1)
#define R(i) (i << 1 | 1)
#define P(i) (i >> 1)
  T _prod(int l, int r, int i, int a, int b) {
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return data[i];
    if(r - l == 1) return data[i];
    T l_val = _prod(l, (l+r)/2, L(i), a, b);
    T r_val = _prod((l+r)/2, r, R(i), a, b);
    return op(l_val, r_val);
  }

public:
  SegmentTree(unsigned length, T e, function<T(T, T)> op)
      : e(e), op(op), n(bit_ceil(length)), data(2 * n, e) {}

  SegmentTree(const vector<T> &v, T e, function<T(T, T)> op)
      : e(e), op(op), n(bit_ceil(v.size())), data(2 * n, e) {
    rep(i, 0, v.size()) data[i + n] = v[i];
    for (int i = n - 1; i > 0; --i)
      data[i] = op(data[L(i)], data[R(i)]);
  }

  void set(int i, T a) {
    i += n;
    data[i] = a;
    while (i = P(i), i > 0)
      data[i] = op(data[L(i)], data[R(i)]);
  }

  T get(int i) { return data[i + n]; }

  T prod(int l, int r) {
    return _prod(0, n, 1, l, r);
  }

#undef L
#undef R
#undef P
};
