#include "../tree/segtree.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp"

int op(int a, int b) {
    return min(a, b);
}
int e() { return ll((1LL << 31) - 1); }
int main() {
    int n, q;
    cin >> n >> q;
    segtree<int, op, e> seg(n);
    while (q--) {
        int com;
        cin >> com;
        int x, y;
        cin >> x >> y;
        if (com == 0) {
            seg.set(x, y);
        } else {
            cout << seg.prod(x, y + 1) << endl;
        }
    }
    return 0;
}