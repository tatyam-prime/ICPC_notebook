#include "test/template.hpp"
using u64 = uint64_t;
#include "src/data-structure/FastSet.hpp"

mt19937 rnd;
int main() {
   auto test = [&](const vector<ll>& query, const string& name, auto add, auto next) {
      using namespace chrono;
      ll ans = 0;
      auto s = system_clock::now();
      for(ll x : query) {
         add(x);
         ans += next(x);
      }
      cout << name << ": " << duration_cast<milliseconds>(system_clock::now() - s).count() << " ms" << endl;
      cerr << ans << endl;
   };

   const ll N = 1 << 21;
   const ll MAX = 1 << 30;
   cout << "N = " << N << ", MAX = " << MAX << endl;
   vector<ll> query(N);
   rep(i, 0, N) query[i] = rnd() >> 2;
   shuffle(all(query), rnd);
   {
      std::set<ll> s;
      test(
          query, "std::set<ll>", [&](ll x) { s.insert(x); },
          [&](ll x) -> ll {
             auto p = s.upper_bound(x);
             if(p == end(s)) return MAX;
             return *p;
          });
   }
   {
      static bitset<MAX> s;
      test(query, "std::bitset", [&](ll x) { s[x] = 1; }, [&](ll x) { return s._Find_next(x); });
   }
   {
      FastSet s(MAX);
      test(query, "FastSet", [&](ll x) { s.set(x); }, [&](ll x) { return s.next(x); });
   }
}
