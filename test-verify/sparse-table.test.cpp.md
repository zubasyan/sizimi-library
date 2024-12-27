---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/sparse-table.hpp
    title: structure/sparse-table.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
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
    #define pb push_back\n#line 2 \"structure/sparse-table.hpp\"\ntemplate <class\
    \ T>\nstruct RMQ {\n    // Sparse Table\n    RMQ() : _n(0) {}\n    explicit RMQ(int\
    \ n, T x_inf) : _n(n) {\n        inf = x_inf;\n        _m = 0;\n        while\
    \ ((1 << _m) <= _n)\n            _m++;\n        table.assign(_m, vector<T>(_n,\
    \ inf));\n    }\n    explicit RMQ(vector<T> v, T x_inf) {\n        inf = x_inf;\n\
    \        _n = sz(v);\n        _m = 0;\n        while ((1 << _m) <= _n)\n     \
    \       _m++;\n        table.assign(_m, vector<T>(_n, inf));\n        table[0]\
    \ = v;\n    }\n    void set(int p, T x) {\n        table[0][p] = x;\n    }\n \
    \   void build() {\n        for (int i = 1; i < _m; i++) {\n            rep(j,\
    \ _n) {\n                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1\
    \ << (i - 1))]);\n            }\n        }\n        log_table.assign(_n + 1, -1);\n\
    \        int j = 0;\n        rep(i, _n + 1) {\n            while (i >= (1 << (j\
    \ + 1)))\n                j++;\n            log_table[i] = j;\n        }\n   \
    \ }\n    T query(int l, int r) {\n        assert(0 <= l && l < r && r <= _n);\n\
    \        // \u533A\u9593\u5E45r-l\u3092\u8D85\u3048\u306A\u3044\u6700\u5927\u306E\
    2^i\u3092\u6C42\u3081\u308B\n        int i = log_table[r - l];\n        return\
    \ min(table[i][l], table[i][r - (1 << i)]);\n    }\n    int _n;\n    int _m;\n\
    \    vector<vector<T>> table;\n    vector<int> log_table;\n    ll inf;\n};\n#line\
    \ 2 \"test-verify/sparse-table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    vi A(N);\n    rep(i,\
    \ N) cin >> A[i];\n    RMQ<int> rmq(A, IINF);\n    rmq.build();\n    while (Q--)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.query(l, r)\
    \ << endl;\n    }\n}\nint main() {\n    int T = 1;\n    // cin>>T;\n    while\
    \ (T--) {\n        solve();\n    }\n    return 0;\n}\n"
  code: "#include \"../structure/sparse-table.hpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    vi A(N);\n    rep(i,\
    \ N) cin >> A[i];\n    RMQ<int> rmq(A, IINF);\n    rmq.build();\n    while (Q--)\
    \ {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.query(l, r)\
    \ << endl;\n    }\n}\nint main() {\n    int T = 1;\n    // cin>>T;\n    while\
    \ (T--) {\n        solve();\n    }\n    return 0;\n}"
  dependsOn:
  - structure/sparse-table.hpp
  - template.hpp
  isVerificationFile: true
  path: test-verify/sparse-table.test.cpp
  requiredBy: []
  timestamp: '2024-12-27 19:35:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test-verify/sparse-table.test.cpp
layout: document
redirect_from:
- /verify/test-verify/sparse-table.test.cpp
- /verify/test-verify/sparse-table.test.cpp.html
title: test-verify/sparse-table.test.cpp
---
