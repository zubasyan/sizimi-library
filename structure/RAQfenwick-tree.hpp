#pragma once
template <class T>
struct fenwick_tree {
public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n + 1), data(n + 1, 0) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++; // 1-originに変換
        while (p < _n) {
            data[p] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        r++, l++; // 1-originに変換
        return sum(r - 1) - sum(l - 1);
    }

    int lower_bound(T w) { // [0,x)Σa_i >=w となる最小のx (外部の添え字で0-origin)
        if (w <= 0)
            return 0;
        else {
            int x = 0, r = 1;
            while (r < _n)
                r = r << 1;
            for (int len = r; len > 0; len = len >> 1) {
                if (x + len < _n && data[x + len] < w) {
                    w -= data[x + len];
                    x += len;
                }
            }
            return x + 1;
        }
    }

private:
    int _n;
    vector<T> data;
    T sum(int r) {
        T ret = 0;
        while (r > 0) {
            ret += data[r];
            r -= r & -r;
        }
        return ret;
    }
};

template <class T>
struct RAQ {
public:
    RAQ() : _n(0) {}
    explicit RAQ(int n) : _n(n + 1),
                          data0(n + 1),
                          data1(n + 1) {}
    void add(int p, T x) {
        assert(0 <= p && p < _n);
        data0.add(p, x);
    }
    void add(int l, int r, T x) {
        assert(0 <= l && l <= r && r <= _n);
        data0.add(l, -x * l);
        data1.add(l, x);
        data0.add(r, x * r);
        data1.add(r, -x);
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }
    T sum(int r) {
        assert(0 <= r && r <= _n);
        //[0,r)の総和を求める *(r-1) ではなく *rにっているのは
        // a_0の寄与を考慮するため
        return data1.sum(0, r) * r + data0.sum(0, r);
    }
    T get(int p) {
        assert(0 <= p && p < _n);
        return sum(p, p + 1);
    }

private:
    int _n;
    fenwick_tree<T> data0, data1;
};