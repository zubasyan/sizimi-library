#include "../structure/sparse-table.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

void solve() {
    int N, Q;
    cin >> N >> Q;
    vi A(N);
    rep(i, N) cin >> A[i];
    RMQ<int> rmq(A, IINF);
    rmq.build();
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << rmq.query(l, r) << endl;
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