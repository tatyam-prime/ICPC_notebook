#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "test/template.hpp"

int main() {
    ll a = 0;
    assert(chmin(a, 1) == 0);
    assert(chmax(a, 1) == 1);
    assert(chmax(a, 1) == 0);
    assert(chmin(a, 0) == 1);
    cout << "Hello World" << endl;
}
