#include "../template.hpp"
template <class T>
struct RMQ {
    // Sparse Table
    RMQ() : _n(0) {}
    explicit RMQ(int n, T x_inf) : _n(n) {
        inf = x_inf;
        _m = 0;
        while ((1 << _m) <= _n)
            _m++;
        table.assign(_m, vector<T>(_n, inf));
    }
    explicit RMQ(vector<T> v, T x_inf) {
        inf = x_inf;
        _n = sz(v);
        _m = 0;
        while ((1 << _m) <= _n)
            _m++;
        table.assign(_m, vector<T>(_n, inf));
        table[0] = v;
    }
    void set(int p, T x) {
        table[0][p] = x;
    }
    void build() {
        for (int i = 1; i < _m; i++) {
            rep(j, _n) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
        log_table.assign(_n + 1, -1);
        int j = 0;
        rep(i, _n + 1) {
            while (i >= (1 << (j + 1)))
                j++;
            log_table[i] = j;
        }
    }
    T query(int l, int r) {
        assert(0 <= l && l < r && r <= _n);
        // 区間幅r-lを超えない最大の2^iを求める
        int i = log_table[r - l];
        return min(table[i][l], table[i][r - (1 << i)]);
    }
    int _n;
    int _m;
    vector<vector<T>> table;
    vector<int> log_table;
    ll inf;
};