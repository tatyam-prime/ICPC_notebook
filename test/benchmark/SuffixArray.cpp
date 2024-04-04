#include "test/template.hpp"
#include "src/string/SuffixArray.hpp"
// #include "atcoder/string"

mt19937 rnd;
int main() {
   using namespace chrono;
   const ll N = 1 << 20;
   string S(N, 0);
   rep(i, 0, N) S[i] = rnd() % 26 + 'A';
   {
      auto s = system_clock::now();
      auto [sa, lcp] = SA(S);
      cout << "my Suffix Array: " << duration_cast<milliseconds>(system_clock::now() - s).count() << " ms" << endl;
   }
   {
      auto s = system_clock::now();
      auto sa = atcoder::suffix_array(S);
      auto lcp = atcoder::lcp_array(S, sa);
      cout << "ACL: " << duration_cast<milliseconds>(system_clock::now() - s).count() << " ms" << endl;
   }
}
