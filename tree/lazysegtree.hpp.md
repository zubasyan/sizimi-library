---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/lazysegtree.test.cpp
    title: test-verify/lazysegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nrandom_device seed_gen;\nmt19937 rnd(seed_gen());\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing vi = vector<int>;\nusing vvi = vector<vi>;\n\
    using vvvi = vector<vvi>;\nusing vl = vector<ll>;\nusing vvl = vector<vl>;\nusing\
    \ vvvl = vector<vvl>;\nusing Pii = pair<int, int>;\nusing Pll = pair<ll, ll>;\n\
    using Pil = pair<int, ll>;\nusing Pli = pair<ll, int>;\ntemplate <typename T>\n\
    inline bool chmax(T &a, T b) {\n    return ((a < b) ? (a = b, true) : (false));\n\
    }\ntemplate <typename T>\ninline bool chmin(T &a, T b) {\n    return ((a > b)\
    \ ? (a = b, true) : (false));\n}\nbool eq(double a, double b) { return abs(a -\
    \ b) < 0.0000001; }\nconst string LRUD = \"LRUD\";\nconst int di4[4] = {0, 0,\
    \ -1, 1}, dj4[4] = {-1, 1, 0, 0};\nconst int di8[8] = {0, 0, 1, 1, 1, -1, -1,\
    \ -1},\n          dj8[8] = {1, -1, 0, -1, 1, 0, -1, 1};\n\n#define rep(i, n) for\
    \ (int i = 0; i < n; i++)\n#define rep1(i, n) for (int i = 1; i <= n; i++)\n#define\
    \ Rrep(i, n) for (int i = n - 1; i >= 0; i--)\n#define Rrep1(i, n) for (int i\
    \ = n; i > 0; i--)\n#define all(a) a.begin(), a.end()\n#if __cplusplus >= 202003L\n\
    #define sz(a) ssize(a)\n#else\n#define sz(a) (a.size())\n#endif\n#define yesno(ans)\
    \ cout << ((ans) ? \"Yes\\n\" : \"No\\n\")\n#define YESNO(ans) cout << ((ans)\
    \ ? \"YES\\n\" : \"NO\\n\")\n#define INF ((ll)2e18)\n#define IINF ((int)(1e9 +\
    \ 5e8))\nconst double PI = 3.1415926535897932384626;\n#define eb emplace_back\n\
    #define pb push_back\n#line 2 \"tree/lazysegtree.hpp\"\ntemplate <typename T,\
    \ auto op, auto e, typename F, auto mapping, auto composition, auto id>\nstruct\
    \ lazy_segtree {\n    static_assert(is_convertible_v<decltype(op), function<T(T,\
    \ T)>>, \"op must work as T(T, T)\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<T()>>, \"e must work as T()\");\n    static_assert(is_convertible_v<decltype(mapping),\
    \ function<T(F, T)>>, \"mapping must work as T(F, T)\");\n    static_assert(is_convertible_v<decltype(composition),\
    \ function<F(F, F)>>, \"composition must work as F(F, F)\");\n    static_assert(is_convertible_v<decltype(id),\
    \ function<F()>>, \"id must work as F()\");\n\npublic:\n    lazy_segtree()\n \
    \       : lazy_segtree(0) {}\n\n    explicit lazy_segtree(int n)\n        : lazy_segtree(vector<T>(n,\
    \ e())) {}\n\n    explicit lazy_segtree(const vector<T> &v)\n        : mn(int(v.size()))\
    \ {\n        msize = 1;\n        while (msize < mn)\n            msize *= 2;\n\
    \        mlog = __builtin_ctz(unsigned(msize));\n        md = vector<T>(2 * msize,\
    \ e());\n        mlz = vector<F>(2 * msize, id());\n        for (int i = 0; i\
    \ < mn; i++)\n            md[msize + i] = v[i];\n\n        for (int i = msize\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n    void set(int\
    \ p, T x) {\n        assert(0 <= p && p < mn);\n        p += msize;\n        for\
    \ (int i = mlog; i >= 1; i--)\n            push(p >> i);\n        md[p] = x;\n\
    \        for (int i = 1; i <= mlog; i++)\n            update(p >> i);\n    }\n\
    \    T get(int p) {\n        assert(0 <= p && p < mn);\n        p += msize;\n\
    \        for (int i = mlog; i >= 1; i--)\n            push(p >> i);\n        return\
    \ md[p + msize];\n    }\n\n    T prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= mn);\n        if (l == r)\n            return e();\n\n      \
    \  l += msize, r += msize;\n        for (int i = mlog; i >= 1; i--) {\n      \
    \      if (((l >> i) << i) != l)\n                push(l >> i);\n            if\
    \ (((r >> i) << i) != r)\n                push((r - 1) >> i);\n        }\n\n \
    \       T sml = e(), smr = e();\n        while (l < r) {\n            if (l &\
    \ 1)\n                sml = op(sml, md[l++]);\n            if (r & 1)\n      \
    \          smr = op(md[--r], smr);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return op(sml, smr);\n    }\n    T all_prod() const { return\
    \ md[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p < mn);\n\
    \        p += msize;\n        for (int i = mlog; i >= 1; i--)\n            push(p\
    \ >> i);\n        md[p] = mapping(f, md[p]);\n        for (int i = 1; i <= mlog;\
    \ i++)\n            update(p >> i);\n    }\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= mn);\n        if (l == r)\n     \
    \       return;\n        l += msize, r += msize;\n        for (int i = mlog; i\
    \ >= 1; i--) {\n            if (((l >> i) << i) != l)\n                push(l\
    \ >> i);\n            if (((r >> i) << i) != r)\n                push((r - 1)\
    \ >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n            while\
    \ (l < r) {\n                if (l & 1)\n                    all_apply(l++, f);\n\
    \                if (r & 1)\n                    all_apply(--r, f);\n        \
    \        l >>= 1;\n                r >>= 1;\n            }\n            l = l2,\
    \ r = r2;\n        }\n        for (int i = 1; i <= mlog; i++) {\n            if\
    \ (((l >> i) << i) != l)\n                update(l >> i);\n            if (((r\
    \ >> i) << i) != r)\n                update((r - 1) >> i);\n        }\n    }\n\
    \n    template <bool (*f)(T)>\n    int max_right(int l) const {\n        return\
    \ max_right(l, [](T x) { return f(x); });\n    }\n\n    template <typename U>\n\
    \    int max_right(int l, U f) const {\n        assert(0 <= l && l <= mn);\n \
    \       assert(f(e()));\n        if (l == mn)\n            return mn;\n      \
    \  l += msize;\n        for (int i = mlog; i >= 1; i--)\n            push(l >>\
    \ i);\n        T sm = e();\n        do {\n            while (l % 2 == 0)\n   \
    \             l >>= 1;\n            if (!f(op(sm, md[l]))) {\n               \
    \ while (l < msize) {\n                    push(l);\n                    l = 2\
    \ * l;\n                    if (f(op(sm, md[l]))) {\n                        sm\
    \ = op(sm, md[l]);\n                        l++;\n                    }\n    \
    \            }\n                return l - msize;\n            }\n           \
    \ sm = op(sm, md[l]);\n            l++;\n        } while ((l & -l) != l);\n  \
    \      return mn;\n    }\n\n    template <bool (*f)(T)>\n    int min_left(int\
    \ r) const {\n        return min_left(r, [](T x) { return f(x); });\n    }\n \
    \   template <typename U>\n    int min_left(int r, U f) const {\n        assert(0\
    \ <= r && r <= mn);\n        assert(f(e()));\n        if (r == 0)\n          \
    \  return 0;\n        r += msize;\n        for (int i = mlog; i >= 1; i--)\n \
    \           push((r - 1) >> i);\n        T sm = e();\n        do {\n         \
    \   r--;\n            while (r > 1 && (r % 2))\n                r >>= 1;\n   \
    \         if (!f(op(md[r], sm))) {\n                while (r < msize) {\n    \
    \                push(r);\n                    r = 2 * r + 1;\n              \
    \      if (f(op(md[r], sm))) {\n                        sm = op(sm, md[r]);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - msize;\n            }\n            sm = op(md[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\nprivate:\n\
    \    int mn, msize, mlog;\n    vector<T> md;\n    vector<F> mlz;\n    void update(int\
    \ k) { md[k] = op(md[2 * k], md[2 * k + 1]); }\n    void all_apply(int k, F f)\
    \ {\n        md[k] = mapping(f, md[k]);\n        if (k < msize)\n            mlz[k]\
    \ = composition(f, mlz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, mlz[k]);\n        all_apply(2 * k + 1, mlz[k]);\n        mlz[k] = id();\n\
    \    }\n};\n"
  code: "#include \"../template.hpp\"\ntemplate <typename T, auto op, auto e, typename\
    \ F, auto mapping, auto composition, auto id>\nstruct lazy_segtree {\n    static_assert(is_convertible_v<decltype(op),\
    \ function<T(T, T)>>, \"op must work as T(T, T)\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<T()>>, \"e must work as T()\");\n    static_assert(is_convertible_v<decltype(mapping),\
    \ function<T(F, T)>>, \"mapping must work as T(F, T)\");\n    static_assert(is_convertible_v<decltype(composition),\
    \ function<F(F, F)>>, \"composition must work as F(F, F)\");\n    static_assert(is_convertible_v<decltype(id),\
    \ function<F()>>, \"id must work as F()\");\n\npublic:\n    lazy_segtree()\n \
    \       : lazy_segtree(0) {}\n\n    explicit lazy_segtree(int n)\n        : lazy_segtree(vector<T>(n,\
    \ e())) {}\n\n    explicit lazy_segtree(const vector<T> &v)\n        : mn(int(v.size()))\
    \ {\n        msize = 1;\n        while (msize < mn)\n            msize *= 2;\n\
    \        mlog = __builtin_ctz(unsigned(msize));\n        md = vector<T>(2 * msize,\
    \ e());\n        mlz = vector<F>(2 * msize, id());\n        for (int i = 0; i\
    \ < mn; i++)\n            md[msize + i] = v[i];\n\n        for (int i = msize\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n    void set(int\
    \ p, T x) {\n        assert(0 <= p && p < mn);\n        p += msize;\n        for\
    \ (int i = mlog; i >= 1; i--)\n            push(p >> i);\n        md[p] = x;\n\
    \        for (int i = 1; i <= mlog; i++)\n            update(p >> i);\n    }\n\
    \    T get(int p) {\n        assert(0 <= p && p < mn);\n        p += msize;\n\
    \        for (int i = mlog; i >= 1; i--)\n            push(p >> i);\n        return\
    \ md[p + msize];\n    }\n\n    T prod(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= mn);\n        if (l == r)\n            return e();\n\n      \
    \  l += msize, r += msize;\n        for (int i = mlog; i >= 1; i--) {\n      \
    \      if (((l >> i) << i) != l)\n                push(l >> i);\n            if\
    \ (((r >> i) << i) != r)\n                push((r - 1) >> i);\n        }\n\n \
    \       T sml = e(), smr = e();\n        while (l < r) {\n            if (l &\
    \ 1)\n                sml = op(sml, md[l++]);\n            if (r & 1)\n      \
    \          smr = op(md[--r], smr);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return op(sml, smr);\n    }\n    T all_prod() const { return\
    \ md[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p < mn);\n\
    \        p += msize;\n        for (int i = mlog; i >= 1; i--)\n            push(p\
    \ >> i);\n        md[p] = mapping(f, md[p]);\n        for (int i = 1; i <= mlog;\
    \ i++)\n            update(p >> i);\n    }\n    void apply(int l, int r, F f)\
    \ {\n        assert(0 <= l && l <= r && r <= mn);\n        if (l == r)\n     \
    \       return;\n        l += msize, r += msize;\n        for (int i = mlog; i\
    \ >= 1; i--) {\n            if (((l >> i) << i) != l)\n                push(l\
    \ >> i);\n            if (((r >> i) << i) != r)\n                push((r - 1)\
    \ >> i);\n        }\n        {\n            int l2 = l, r2 = r;\n            while\
    \ (l < r) {\n                if (l & 1)\n                    all_apply(l++, f);\n\
    \                if (r & 1)\n                    all_apply(--r, f);\n        \
    \        l >>= 1;\n                r >>= 1;\n            }\n            l = l2,\
    \ r = r2;\n        }\n        for (int i = 1; i <= mlog; i++) {\n            if\
    \ (((l >> i) << i) != l)\n                update(l >> i);\n            if (((r\
    \ >> i) << i) != r)\n                update((r - 1) >> i);\n        }\n    }\n\
    \n    template <bool (*f)(T)>\n    int max_right(int l) const {\n        return\
    \ max_right(l, [](T x) { return f(x); });\n    }\n\n    template <typename U>\n\
    \    int max_right(int l, U f) const {\n        assert(0 <= l && l <= mn);\n \
    \       assert(f(e()));\n        if (l == mn)\n            return mn;\n      \
    \  l += msize;\n        for (int i = mlog; i >= 1; i--)\n            push(l >>\
    \ i);\n        T sm = e();\n        do {\n            while (l % 2 == 0)\n   \
    \             l >>= 1;\n            if (!f(op(sm, md[l]))) {\n               \
    \ while (l < msize) {\n                    push(l);\n                    l = 2\
    \ * l;\n                    if (f(op(sm, md[l]))) {\n                        sm\
    \ = op(sm, md[l]);\n                        l++;\n                    }\n    \
    \            }\n                return l - msize;\n            }\n           \
    \ sm = op(sm, md[l]);\n            l++;\n        } while ((l & -l) != l);\n  \
    \      return mn;\n    }\n\n    template <bool (*f)(T)>\n    int min_left(int\
    \ r) const {\n        return min_left(r, [](T x) { return f(x); });\n    }\n \
    \   template <typename U>\n    int min_left(int r, U f) const {\n        assert(0\
    \ <= r && r <= mn);\n        assert(f(e()));\n        if (r == 0)\n          \
    \  return 0;\n        r += msize;\n        for (int i = mlog; i >= 1; i--)\n \
    \           push((r - 1) >> i);\n        T sm = e();\n        do {\n         \
    \   r--;\n            while (r > 1 && (r % 2))\n                r >>= 1;\n   \
    \         if (!f(op(md[r], sm))) {\n                while (r < msize) {\n    \
    \                push(r);\n                    r = 2 * r + 1;\n              \
    \      if (f(op(md[r], sm))) {\n                        sm = op(sm, md[r]);\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - msize;\n            }\n            sm = op(md[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\nprivate:\n\
    \    int mn, msize, mlog;\n    vector<T> md;\n    vector<F> mlz;\n    void update(int\
    \ k) { md[k] = op(md[2 * k], md[2 * k + 1]); }\n    void all_apply(int k, F f)\
    \ {\n        md[k] = mapping(f, md[k]);\n        if (k < msize)\n            mlz[k]\
    \ = composition(f, mlz[k]);\n    }\n    void push(int k) {\n        all_apply(2\
    \ * k, mlz[k]);\n        all_apply(2 * k + 1, mlz[k]);\n        mlz[k] = id();\n\
    \    }\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/lazysegtree.hpp
  requiredBy: []
  timestamp: '2025-02-09 13:26:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/lazysegtree.test.cpp
documentation_of: tree/lazysegtree.hpp
layout: document
redirect_from:
- /library/tree/lazysegtree.hpp
- /library/tree/lazysegtree.hpp.html
title: tree/lazysegtree.hpp
---
