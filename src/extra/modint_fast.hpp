const uint32_t mod = 998244353;
struct mm {
   uint32_t x;
   mm() : x(0) {}
   template<class T> mm(T x_) : x(x_ % mod) {
      if(x >= mod) x += mod;
   }
   friend mm operator+(mm a, mm b) {
      a.x += b.x;
      if(a.x >= mod) a.x -= mod;
      return a;
   }
   friend mm operator-(mm a, mm b) {
      a.x -= b.x;
      if(a.x >= mod) a.x += mod;
      return a;
   }
   friend mm operator*(mm a, mm b) { return (uint64_t)a.x * b.x; }
   friend mm operator/(mm a, mm b) { return a * b.inv(); }
   friend mm& operator+=(mm& a, mm b) { return a = a + b; }
   friend mm& operator-=(mm& a, mm b) { return a = a - b; }
   friend mm& operator*=(mm& a, mm b) { return a = a * b; }
   friend mm& operator/=(mm& a, mm b) { return a = a * b.inv(); }
   mm inv() const { return pow(mod - 2); }
   mm pow(ll b) const {
      mm a = *this, c = 1;
      while(b) {
         if(b & 1) c *= a;
         a *= a;
         b >>= 1;
      }
      return c;
   }
};
