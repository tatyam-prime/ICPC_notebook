#include "test/template.hpp"
#include "src/string/SuffixArray.hpp"
#include <atcoder/string>

mt19937 rnd;
int main() {
   using namespace chrono;
   const ll N = 1 << 20;
   constexpr ll T = 10;
   string S(N, 0);
   rep(i, 0, N) S[i] = rnd() % 26 + 'A';
   double my_time = 0, acl_time = 0;
   rep(_, 0, T) {
      {
         auto s = steady_clock::now();
         auto [sa, lcp] = SA(S);
         my_time += duration<double, milli>(steady_clock::now() - s).count();
      }
      {
         auto s = steady_clock::now();
         auto sa = atcoder::suffix_array(S);
         auto lcp = atcoder::lcp_array(S, sa);
         acl_time += duration<double, milli>(steady_clock::now() - s).count();
      }
   }
   cout << "my Suffix Array: " << my_time / T << " ms" << endl;
   cout << "ACL: " << acl_time / T << " ms" << endl;
}
