#include "../number-theory/eulers-phi-function.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D&lang=jp"

void solve() {
    ll n;
    cin >> n;
    cout << phi(n) << "\n";
}

int main() {
    solve();
}