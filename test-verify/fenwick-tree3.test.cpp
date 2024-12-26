#include "../template.hpp"

#include "../structure/fenwick-tree2D.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

void solve() {
    int H, W, T, Q;
    cin >> H >> W >> T >> Q;
    fenwick_tree2D<int> ft0(H, W); // すでに焼きあがったたい焼き
    fenwick_tree2D<int> ft1(H, W); // まだ焼きあがっていないたい焼き
    vvi memo(H, vi(W, -1));
    using Pair = pair<int, Pii>; // 時間と座標
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    while (Q--) {
        int t, c;
        cin >> t >> c;
        // たい焼きの焼き上がりを見る
        while (!q.empty()) {
            int tt = q.top().first;
            auto [r, c] = q.top().second;
            if (t - tt < T)
                break;
            if (memo[r][c] != -1) {
                // 焼きあがっているかつたい焼きがある
                ft1.add(r, c, -1);
                ft0.add(r, c, 1);
            }
            q.pop();
        }

        if (c == 0) {
            int h, w;
            cin >> h >> w;
            h--, w--;
            memo[h][w] = t;
            ft1.add(h, w, 1);
            q.push(Pair(t, Pii(h, w)));
        } else if (c == 1) {
            int h, w;
            cin >> h >> w;
            h--, w--;
            if (ft0.sum(h, w, h + 1, w + 1) == 1) {
                ft0.add(h, w, -1);
                memo[h][w] = -1;
            }
        } else if (c == 2) {
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            h1--, w1--;
            cout << ft0.sum(h1, w1, h2, w2) << " " << ft1.sum(h1, w1, h2, w2) << endl;
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