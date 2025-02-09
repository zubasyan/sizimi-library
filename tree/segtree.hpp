#include "../template.hpp"
template <typename T, auto op, auto e>
struct segtree {
    static_assert(is_convertible_v<decltype(op), function<T(T, T)>>, "op must work as S(S,S)");
    static_assert(is_convertible_v<decltype(e), function<T()>>, "e must work as S()");

public:
    segtree()
        : segtree(0) {}
    explicit segtree(int n)
        : segtree(vector<T>(n, e())) {}
    explicit segtree(const vector<T> &v)
        : mn(int(v.size())) {
        msize = 1;
        while (msize < mn)
            msize *= 2;
        mlog = __builtin_ctz(unsigned(msize));
        md = vector<T>(2 * msize, e());
        for (int i = 0; i < mn; i++)
            md[msize + i] = v[i];
        for (int i = msize - 1; i >= 1; i--) {
            update(i);
        }
    }
    void set(int p, T x) {
        assert(0 <= p && p < mn);
        p += msize;
        md[p] = x;
        for (int i = 1; i <= mlog; i++)
            update(p >> i);
    }
    T get(int p) const {
        assert(0 <= p && p < mn);
        return md[p + msize];
    }

    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= mn);
        T sml = e(), smr = e();
        l += msize, r += msize;
        while (l < r) {
            if (l & 1)
                sml = op(sml, md[l++]);
            if (r & 1)
                smr = op(md[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
    T all_prod() const { return md[1]; }

    template <bool (*f)(T)>
    int max_right(int l) const {
        return max_right(l, [](T x) { return f(x); });
    }

    template <typename U>
    int max_right(int l, U f) const {
        assert(0 <= l && l <= mn);
        assert(f(e()));
        if (l == mn)
            return mn;
        l += msize;
        T sm = e();
        do {
            while (l % 2 == 0)
                l >>= 1;
            if (!f(op(sm, md[l]))) {
                while (l < msize) {
                    l = 2 * l;
                    if (f(op(sm, md[l]))) {
                        sm = op(sm, md[l]);
                        l++;
                    }
                }
                return l - msize;
            }
            sm = op(sm, md[l]);
            l++;
        } while ((l & -l) != l);
        return mn;
    }

    template <bool (*f)(T)>
    int min_left(int r) const {
        return min_left(r, [](T x) { return f(x); });
    }
    template <typename U>
    int min_left(int r, U f) const {
        assert(0 <= r && r <= mn);
        assert(f(e()));
        if (r == 0)
            return 0;
        r += msize;
        T sm = e();
        do {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!f(op(md[r], sm))) {
                while (r < msize) {
                    r = 2 * r + 1;
                    if (f(op(md[r], sm))) {
                        sm = op(sm, md[r]);
                        r--;
                    }
                }
                return r + 1 - msize;
            }
            sm = op(md[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

private:
    int mn, msize, mlog;
    vector<T> md;
    void update(int k) { md[k] = op(md[2 * k], md[2 * k + 1]); }
};
