#include "../tree/lca_tree.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja"

void solve() {
    int N;
    cin >> N;
    lca_tree G(N);
    rep(i, N) {
        int k;
        cin >> k;
        rep(j, k) {
            int u;
            cin >> u;
            G.add_edge(i, u);
        }
    }
    G.build();
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << G.lca(u, v) << endl;
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