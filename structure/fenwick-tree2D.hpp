#pragma once
template <class T>
struct fenwick_tree2D {
public:
    fenwick_tree2D() : _h(0), _w(0) {}
    explicit fenwick_tree2D(int h, int w) : _h(h + 1), _w(w + 1), data(h + 1, vector<T>(w + 1, 0)) {}

    void add(int r, int c, T x) {
        r++, c++; // 1-originに変換
        for (int i = r; i < _h; i += (i & -i)) {
            for (int j = c; j < _w; j += (j & -j)) {
                data[i][j] += x;
            }
        }
    }

    T sum(int r, int c) {
        T ret = 0;
        // r++, c++; // 1-originに変換 r++,c++
        // r--, c--; // 開区間に変換 r--,c-- ->あわせるとかわらない
        for (int i = r; i > 0; i -= (i & -i)) {
            for (int j = c; j > 0; j -= (j & -j)) {
                ret += data[i][j];
            }
        }
        return ret;
    }

    T sum(int r1, int c1, int r2, int c2) {
        return +sum(r2, c2) + sum(r1, c1) - sum(r1, c2) - sum(r2, c1);
    }

private:
    int _h, _w;
    vector<vector<T>> data;
};