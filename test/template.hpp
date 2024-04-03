#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
#define rep(i, a, b) for(ll i = a; i < (b); i++)
#define all(a) begin(a), end(a)
#define sz(a) ssize(a)
bool chmin(auto& a, auto b) {
   if(a <= b) return 0;
   a = b;
   return 1;
}
bool chmax(auto& a, auto b) {
   if(a >= b) return 0;
   a = b;
   return 1;
}
