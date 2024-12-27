#include "../template.hpp"
struct lca_tree {
    lca_tree() : _n(0) {}
    lca_tree(int n) : _n(n), G(n) {}
    void add_edge(int u, int v) {
        G[u].pb(v);
        G[v].pb(u);
    }
    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto to : G[v]) {
            if (to != p)
                dfs(to, v, d + 1);
        }
    }
    void build() {
        max_k = 0;
        while ((1 << max_k) < _n)
            max_k++;

        max_k += 2; // 念のため.exe
        parent.assign(max_k, vi(_n, -1));
        depth.assign(_n, -1);

        dfs(0, -1, 0); // parent,depthを初期化
        for (int k = 0; k + 1 < max_k; k++) {
            for (int v = 0; v < _n; v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
    int lca(int u, int v) { // 頂点u,vのlcaを求める
        if (depth[u] > depth[v])
            swap(u, v);
        // u,vの深さを同じにする
        for (int k = 0; k < max_k; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v)
            return u;
        for (int k = max_k - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    int dist(int u, int v) {
        return depth[u] + depth[v] - depth[lca(u, v)] * 2;
    }
    int _n;     // 頂点数
    vvi G;      // 木(向無辺)
    vi depth;   // 根からの深さ
    vvi parent; // 親を2^k回たどって到達する頂点(ないなら-1)
    int max_k;
};
