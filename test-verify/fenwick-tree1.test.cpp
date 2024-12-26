#include "../template.hpp"

#include "../structure/fenwick-tree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

void solve() {
    int N, Q;
    cin >> N >> Q;
    fenwick_tree<ll> ft(N);
    while (Q--) {
        int c;
        cin >> c;
        if (c == 0) {
            int x, y;
            cin >> x >> y;
            x--;
            ft.add(x, y);
        } else {
            int x, y;
            cin >> x >> y;
            x--;
            cout << ft.sum(x, y) << endl;
        }
    }
}

int main() {
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
    return 0;
}