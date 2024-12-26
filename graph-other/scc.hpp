#include "../template.hpp"
struct scc_graph {
public:
    scc_graph() : _n(0) {}
    explicit scc_graph(int n) : _n(n), G(n), rG(n), used(n), cmp(n) {}
    void add_edge(int from, int to) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        G[from].pb(to);
        rG[to].pb(from);
    }
    void dfs(int v) { // vからdfs
        used[v] = true;
        for (auto to : G[v]) {
            if (!used[to])
                dfs(to);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k) { // 逆辺でvからdfs
        used[v] = true;
        cmp[v] = k;
        for (auto to : rG[v]) {
            if (!used[to])
                rdfs(to, k);
        }
    }
    void scc() { // sccを構築
        used.assign(_n, 0);
        vs.clear();
        rep(i, _n) if (!used[i]) dfs(i);
        used.assign(_n, 0);
        int k = 0;
        for (int i = sz(vs) - 1; i >= 0; i--) {
            if (!used[vs[i]])
                rdfs(vs[i], k++);
        }
    }

    int _n;
    vvi G, rG; // 辺と逆辺
    vi used;   // すでに調べたか、
    vi vs;     //    帰りがけ順
    vi cmp;    // トポロジカル順序 つまり 強連結成分のグループ番号
};