---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/segtree1.test.cpp
    title: test-verify/segtree1.test.cpp
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
    #define pb push_back\n#line 2 \"tree/segtree.hpp\"\ntemplate <typename T, auto\
    \ op, auto e>\nstruct segtree {\n    static_assert(is_convertible_v<decltype(op),\
    \ function<T(T, T)>>, \"op must work as S(S,S)\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<T()>>, \"e must work as S()\");\n\npublic:\n    segtree()\n       \
    \ : segtree(0) {}\n    explicit segtree(int n)\n        : segtree(vector<T>(n,\
    \ e())) {}\n    explicit segtree(const vector<T> &v)\n        : mn(int(v.size()))\
    \ {\n        msize = 1;\n        while (msize < mn)\n            msize *= 2;\n\
    \        mlog = __builtin_ctz(unsigned(msize));\n        md = vector<T>(2 * msize,\
    \ e());\n        for (int i = 0; i < mn; i++)\n            md[msize + i] = v[i];\n\
    \        for (int i = msize - 1; i >= 1; i--) {\n            update(i);\n    \
    \    }\n    }\n    void set(int p, T x) {\n        assert(0 <= p && p < mn);\n\
    \        p += msize;\n        md[p] = x;\n        for (int i = 1; i <= mlog; i++)\n\
    \            update(p >> i);\n    }\n    T get(int p) const {\n        assert(0\
    \ <= p && p < mn);\n        return md[p + msize];\n    }\n\n    T prod(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= mn);\n        T sml\
    \ = e(), smr = e();\n        l += msize, r += msize;\n        while (l < r) {\n\
    \            if (l & 1)\n                sml = op(sml, md[l++]);\n           \
    \ if (r & 1)\n                smr = op(md[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n    T all_prod()\
    \ const { return md[1]; }\n\n    template <bool (*f)(T)>\n    int max_right(int\
    \ l) const {\n        return max_right(l, [](T x) { return f(x); });\n    }\n\n\
    \    template <typename U>\n    int max_right(int l, U f) const {\n        assert(0\
    \ <= l && l <= mn);\n        assert(f(e()));\n        if (l == mn)\n         \
    \   return mn;\n        l += msize;\n        T sm = e();\n        do {\n     \
    \       while (l % 2 == 0)\n                l >>= 1;\n            if (!f(op(sm,\
    \ md[l]))) {\n                while (l < msize) {\n                    l = 2 *\
    \ l;\n                    if (f(op(sm, md[l]))) {\n                        sm\
    \ = op(sm, md[l]);\n                        l++;\n                    }\n    \
    \            }\n                return l - msize;\n            }\n           \
    \ sm = op(sm, md[l]);\n            l++;\n        } while ((l & -l) != l);\n  \
    \      return mn;\n    }\n\n    template <bool (*f)(T)>\n    int min_left(int\
    \ r) const {\n        return min_left(r, [](T x) { return f(x); });\n    }\n \
    \   template <typename U>\n    int min_left(int r, U f) const {\n        assert(0\
    \ <= r && r <= mn);\n        assert(f(e()));\n        if (r == 0)\n          \
    \  return 0;\n        r += msize;\n        T sm = e();\n        do {\n       \
    \     r--;\n            while (r > 1 && (r % 2))\n                r >>= 1;\n \
    \           if (!f(op(md[r], sm))) {\n                while (r < msize) {\n  \
    \                  r = 2 * r + 1;\n                    if (f(op(md[r], sm))) {\n\
    \                        sm = op(sm, md[r]);\n                        r--;\n \
    \                   }\n                }\n                return r + 1 - msize;\n\
    \            }\n            sm = op(md[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n\nprivate:\n    int mn, msize, mlog;\n    vector<T>\
    \ md;\n    void update(int k) { md[k] = op(md[2 * k], md[2 * k + 1]); }\n};\n"
  code: "#include \"../template.hpp\"\ntemplate <typename T, auto op, auto e>\nstruct\
    \ segtree {\n    static_assert(is_convertible_v<decltype(op), function<T(T, T)>>,\
    \ \"op must work as S(S,S)\");\n    static_assert(is_convertible_v<decltype(e),\
    \ function<T()>>, \"e must work as S()\");\n\npublic:\n    segtree()\n       \
    \ : segtree(0) {}\n    explicit segtree(int n)\n        : segtree(vector<T>(n,\
    \ e())) {}\n    explicit segtree(const vector<T> &v)\n        : mn(int(v.size()))\
    \ {\n        msize = 1;\n        while (msize < mn)\n            msize *= 2;\n\
    \        mlog = __builtin_ctz(unsigned(msize));\n        md = vector<T>(2 * msize,\
    \ e());\n        for (int i = 0; i < mn; i++)\n            md[msize + i] = v[i];\n\
    \        for (int i = msize - 1; i >= 1; i--) {\n            update(i);\n    \
    \    }\n    }\n    void set(int p, T x) {\n        assert(0 <= p && p < mn);\n\
    \        p += msize;\n        md[p] = x;\n        for (int i = 1; i <= mlog; i++)\n\
    \            update(p >> i);\n    }\n    T get(int p) const {\n        assert(0\
    \ <= p && p < mn);\n        return md[p + msize];\n    }\n\n    T prod(int l,\
    \ int r) const {\n        assert(0 <= l && l <= r && r <= mn);\n        T sml\
    \ = e(), smr = e();\n        l += msize, r += msize;\n        while (l < r) {\n\
    \            if (l & 1)\n                sml = op(sml, md[l++]);\n           \
    \ if (r & 1)\n                smr = op(md[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n    T all_prod()\
    \ const { return md[1]; }\n\n    template <bool (*f)(T)>\n    int max_right(int\
    \ l) const {\n        return max_right(l, [](T x) { return f(x); });\n    }\n\n\
    \    template <typename U>\n    int max_right(int l, U f) const {\n        assert(0\
    \ <= l && l <= mn);\n        assert(f(e()));\n        if (l == mn)\n         \
    \   return mn;\n        l += msize;\n        T sm = e();\n        do {\n     \
    \       while (l % 2 == 0)\n                l >>= 1;\n            if (!f(op(sm,\
    \ md[l]))) {\n                while (l < msize) {\n                    l = 2 *\
    \ l;\n                    if (f(op(sm, md[l]))) {\n                        sm\
    \ = op(sm, md[l]);\n                        l++;\n                    }\n    \
    \            }\n                return l - msize;\n            }\n           \
    \ sm = op(sm, md[l]);\n            l++;\n        } while ((l & -l) != l);\n  \
    \      return mn;\n    }\n\n    template <bool (*f)(T)>\n    int min_left(int\
    \ r) const {\n        return min_left(r, [](T x) { return f(x); });\n    }\n \
    \   template <typename U>\n    int min_left(int r, U f) const {\n        assert(0\
    \ <= r && r <= mn);\n        assert(f(e()));\n        if (r == 0)\n          \
    \  return 0;\n        r += msize;\n        T sm = e();\n        do {\n       \
    \     r--;\n            while (r > 1 && (r % 2))\n                r >>= 1;\n \
    \           if (!f(op(md[r], sm))) {\n                while (r < msize) {\n  \
    \                  r = 2 * r + 1;\n                    if (f(op(md[r], sm))) {\n\
    \                        sm = op(sm, md[r]);\n                        r--;\n \
    \                   }\n                }\n                return r + 1 - msize;\n\
    \            }\n            sm = op(md[r], sm);\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n\nprivate:\n    int mn, msize, mlog;\n    vector<T>\
    \ md;\n    void update(int k) { md[k] = op(md[2 * k], md[2 * k + 1]); }\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/segtree.hpp
  requiredBy: []
  timestamp: '2025-02-09 13:26:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/segtree1.test.cpp
documentation_of: tree/segtree.hpp
layout: document
redirect_from:
- /library/tree/segtree.hpp
- /library/tree/segtree.hpp.html
title: tree/segtree.hpp
---
