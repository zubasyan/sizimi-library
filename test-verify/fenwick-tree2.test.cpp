#include "../template.hpp"

#include "../structure/RAQfenwick-tree.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

void solve() {
    int N, Q;
    cin >> N >> Q;
    RAQ<int> raq(N);
    while (Q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            s--;
            raq.add(s, t, x);
        } else if (op == 1) {
            int i;
            cin >> i;
            i--;
            cout << raq.get(i) << endl;
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