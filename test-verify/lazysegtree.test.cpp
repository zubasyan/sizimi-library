#include "../tree/lazysegtree.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja"

const int inf = (1LL << 31) - 1;
int op(int a, int b) { return min(a, b); }
int e() { return inf; }
int mp(int f, int x) { return f == inf ? x : f; }
int cp(int f, int g) { return f == inf ? g : f; }
int id() { return ll((1LL << 31) - 1); }
int main() {
    int n, q;
    cin >> n >> q;
    lazy_segtree<int, op, e, int, mp, cp, id> seg(n);

    rep(i, q) {
        int op;
        cin >> op;
        if (op == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            t++;
            seg.apply(s, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            t++;
            cout << seg.prod(s, t) << endl;
        }
    }
    return 0;
}
