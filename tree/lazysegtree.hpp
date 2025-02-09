#include "../template.hpp"
template <typename T, auto op, auto e, typename F, auto mapping, auto composition, auto id>
struct lazy_segtree {
    static_assert(is_convertible_v<decltype(op), function<T(T, T)>>, "op must work as T(T, T)");
    static_assert(is_convertible_v<decltype(e), function<T()>>, "e must work as T()");
    static_assert(is_convertible_v<decltype(mapping), function<T(F, T)>>, "mapping must work as T(F, T)");
    static_assert(is_convertible_v<decltype(composition), function<F(F, F)>>, "composition must work as F(F, F)");
    static_assert(is_convertible_v<decltype(id), function<F()>>, "id must work as F()");

public:
    lazy_segtree()
        : lazy_segtree(0) {}

    explicit lazy_segtree(int n)
        : lazy_segtree(vector<T>(n, e())) {}

    explicit lazy_segtree(const vector<T> &v)
        : mn(int(v.size())) {
        msize = 1;
        while (msize < mn)
            msize *= 2;
        mlog = __builtin_ctz(unsigned(msize));
        md = vector<T>(2 * msize, e());
        mlz = vector<F>(2 * msize, id());
        for (int i = 0; i < mn; i++)
            md[msize + i] = v[i];

        for (int i = msize - 1; i >= 1; i--) {
            update(i);
        }
    }
    void set(int p, T x) {
        assert(0 <= p && p < mn);
        p += msize;
        for (int i = mlog; i >= 1; i--)
            push(p >> i);
        md[p] = x;
        for (int i = 1; i <= mlog; i++)
            update(p >> i);
    }
    T get(int p) {
        assert(0 <= p && p < mn);
        p += msize;
        for (int i = mlog; i >= 1; i--)
            push(p >> i);
        return md[p + msize];
    }

    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= mn);
        if (l == r)
            return e();

        l += msize, r += msize;
        for (int i = mlog; i >= 1; i--) {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }

        T sml = e(), smr = e();
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

    void apply(int p, F f) {
        assert(0 <= p && p < mn);
        p += msize;
        for (int i = mlog; i >= 1; i--)
            push(p >> i);
        md[p] = mapping(f, md[p]);
        for (int i = 1; i <= mlog; i++)
            update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= mn);
        if (l == r)
            return;
        l += msize, r += msize;
        for (int i = mlog; i >= 1; i--) {
            if (((l >> i) << i) != l)
                push(l >> i);
            if (((r >> i) << i) != r)
                push((r - 1) >> i);
        }
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1)
                    all_apply(l++, f);
                if (r & 1)
                    all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2, r = r2;
        }
        for (int i = 1; i <= mlog; i++) {
            if (((l >> i) << i) != l)
                update(l >> i);
            if (((r >> i) << i) != r)
                update((r - 1) >> i);
        }
    }

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
        for (int i = mlog; i >= 1; i--)
            push(l >> i);
        T sm = e();
        do {
            while (l % 2 == 0)
                l >>= 1;
            if (!f(op(sm, md[l]))) {
                while (l < msize) {
                    push(l);
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
        for (int i = mlog; i >= 1; i--)
            push((r - 1) >> i);
        T sm = e();
        do {
            r--;
            while (r > 1 && (r % 2))
                r >>= 1;
            if (!f(op(md[r], sm))) {
                while (r < msize) {
                    push(r);
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
    vector<F> mlz;
    void update(int k) { md[k] = op(md[2 * k], md[2 * k + 1]); }
    void all_apply(int k, F f) {
        md[k] = mapping(f, md[k]);
        if (k < msize)
            mlz[k] = composition(f, mlz[k]);
    }
    void push(int k) {
        all_apply(2 * k, mlz[k]);
        all_apply(2 * k + 1, mlz[k]);
        mlz[k] = id();
    }
};