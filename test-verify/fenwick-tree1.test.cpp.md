---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/fenwick-tree.hpp
    title: structure/fenwick-tree.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
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
    #define pb push_back\n#line 2 \"test-verify/fenwick-tree1.test.cpp\"\n\n#line\
    \ 2 \"structure/fenwick-tree.hpp\"\ntemplate <class T>\nstruct fenwick_tree {\n\
    public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n\
    \ + 1), data(n + 1, 0) {}\n\n    void add(int p, T x) {\n        assert(0 <= p\
    \ && p < _n);\n        p++; // 1-origin\u306B\u5909\u63DB\n        while (p <\
    \ _n) {\n            data[p] += x;\n            p += p & -p;\n        }\n    }\n\
    \n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n  \
    \      r++, l++; // 1-origin\u306B\u5909\u63DB\n        return sum(r - 1) - sum(l\
    \ - 1);\n    }\n\n    int lower_bound(T w) { // [0,x)\u03A3a_i >=w \u3068\u306A\
    \u308B\u6700\u5C0F\u306Ex (\u5916\u90E8\u306E\u6DFB\u3048\u5B57\u30670-origin)\n\
    \        if (w <= 0)\n            return 0;\n        else {\n            int x\
    \ = 0, r = 1;\n            while (r < _n)\n                r = r << 1;\n     \
    \       for (int len = r; len > 0; len = len >> 1) {\n                if (x +\
    \ len < _n && data[x + len] < w) {\n                    w -= data[x + len];\n\
    \                    x += len;\n                }\n            }\n           \
    \ return x + 1;\n        }\n    }\n\nprivate:\n    int _n;\n    vector<T> data;\n\
    \    T sum(int r) {\n        T ret = 0;\n        while (r > 0) {\n           \
    \ ret += data[r];\n            r -= r & -r;\n        }\n        return ret;\n\
    \    }\n};\n#line 4 \"test-verify/fenwick-tree1.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\n\nvoid solve()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    fenwick_tree<ll> ft(N);\n    while\
    \ (Q--) {\n        int c;\n        cin >> c;\n        if (c == 0) {\n        \
    \    int x, y;\n            cin >> x >> y;\n            x--;\n            ft.add(x,\
    \ y);\n        } else {\n            int x, y;\n            cin >> x >> y;\n \
    \           x--;\n            cout << ft.sum(x, y) << endl;\n        }\n    }\n\
    }\n\nint main() {\n    int T = 1;\n    // cin>>T;\n    while (T--) {\n       \
    \ solve();\n    }\n    return 0;\n}\n"
  code: "#include \"../template.hpp\"\n\n#include \"../structure/fenwick-tree.hpp\"\
    \n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    fenwick_tree<ll> ft(N);\n\
    \    while (Q--) {\n        int c;\n        cin >> c;\n        if (c == 0) {\n\
    \            int x, y;\n            cin >> x >> y;\n            x--;\n       \
    \     ft.add(x, y);\n        } else {\n            int x, y;\n            cin\
    \ >> x >> y;\n            x--;\n            cout << ft.sum(x, y) << endl;\n  \
    \      }\n    }\n}\n\nint main() {\n    int T = 1;\n    // cin>>T;\n    while\
    \ (T--) {\n        solve();\n    }\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - structure/fenwick-tree.hpp
  isVerificationFile: true
  path: test-verify/fenwick-tree1.test.cpp
  requiredBy: []
  timestamp: '2024-12-26 21:12:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test-verify/fenwick-tree1.test.cpp
layout: document
redirect_from:
- /verify/test-verify/fenwick-tree1.test.cpp
- /verify/test-verify/fenwick-tree1.test.cpp.html
title: test-verify/fenwick-tree1.test.cpp
---
