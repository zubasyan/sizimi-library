#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include "../tree/DSU_W.hpp"
void solve() {
    int N, Q;
    cin >> N >> Q;
    DSU_W<ll> uf(N);
    while (Q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            uf.merge(x, y, z);
        } else if (op == 1) {
            int x, y;
            cin >> x >> y;
            if (uf.same(x, y))
                cout << uf.diff(x, y) << "\n";
            else
                cout << "?\n";
        } else {
            cerr << "error!" << endl;
            return;
        }
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}