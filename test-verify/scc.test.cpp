#include "../graph-other/scc.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

void solve() {
    int N, M;
    cin >> N >> M;
    scc_graph SG(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        SG.add_edge(a, b);
    }
    SG.scc();
    int Q;
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << (SG.cmp[u] == SG.cmp[v] ? 1 : 0) << endl;
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