---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/fenwick-tree2D.hpp
    title: structure/fenwick-tree2D.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
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
    \ = n; i > 0; i--)\n#define all(a) a.begin(), a.end()\n#define sz(a) ssize(a)\n\
    #define yesno(ans) cout << ((ans) ? \"Yes\\n\" : \"No\\n\")\n#define YESNO(ans)\
    \ cout << ((ans) ? \"YES\\n\" : \"NO\\n\")\n#define INF ((ll)2e18)\n#define IINF\
    \ ((int)(1e9 + 5e8))\nconst double PI = 3.1415926535897932384626;\n#define eb\
    \ emplace_back\n#define pb push_back\n#line 2 \"test-verify/fenwick-tree3.test.cpp\"\
    \n\n#line 2 \"structure/fenwick-tree2D.hpp\"\ntemplate <class T>\nstruct fenwick_tree2D\
    \ {\npublic:\n    fenwick_tree2D() : _h(0), _w(0) {}\n    explicit fenwick_tree2D(int\
    \ h, int w) : _h(h + 1), _w(w + 1), data(h + 1, vector<T>(w + 1, 0)) {}\n\n  \
    \  void add(int r, int c, T x) {\n        r++, c++; // 1-origin\u306B\u5909\u63DB\
    \n        for (int i = r; i < _h; i += (i & -i)) {\n            for (int j = c;\
    \ j < _w; j += (j & -j)) {\n                data[i][j] += x;\n            }\n\
    \        }\n    }\n\n    T sum(int r, int c) {\n        T ret = 0;\n        //\
    \ r++, c++; // 1-origin\u306B\u5909\u63DB r++,c++\n        // r--, c--; // \u958B\
    \u533A\u9593\u306B\u5909\u63DB r--,c-- ->\u3042\u308F\u305B\u308B\u3068\u304B\u308F\
    \u3089\u306A\u3044\n        for (int i = r; i > 0; i -= (i & -i)) {\n        \
    \    for (int j = c; j > 0; j -= (j & -j)) {\n                ret += data[i][j];\n\
    \            }\n        }\n        return ret;\n    }\n\n    T sum(int r1, int\
    \ c1, int r2, int c2) {\n        return +sum(r2, c2) + sum(r1, c1) - sum(r1, c2)\
    \ - sum(r2, c1);\n    }\n\nprivate:\n    int _h, _w;\n    vector<vector<T>> data;\n\
    };\n#line 4 \"test-verify/fenwick-tree3.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \n\nvoid solve() {\n    int H, W, T, Q;\n    cin >> H >> W >> T >> Q;\n    fenwick_tree2D<int>\
    \ ft0(H, W); // \u3059\u3067\u306B\u713C\u304D\u3042\u304C\u3063\u305F\u305F\u3044\
    \u713C\u304D\n    fenwick_tree2D<int> ft1(H, W); // \u307E\u3060\u713C\u304D\u3042\
    \u304C\u3063\u3066\u3044\u306A\u3044\u305F\u3044\u713C\u304D\n    vvi memo(H,\
    \ vi(W, -1));\n    using Pair = pair<int, Pii>; // \u6642\u9593\u3068\u5EA7\u6A19\
    \n    priority_queue<Pair, vector<Pair>, greater<Pair>> q;\n    while (Q--) {\n\
    \        int t, c;\n        cin >> t >> c;\n        // \u305F\u3044\u713C\u304D\
    \u306E\u713C\u304D\u4E0A\u304C\u308A\u3092\u898B\u308B\n        while (!q.empty())\
    \ {\n            int tt = q.top().first;\n            auto [r, c] = q.top().second;\n\
    \            if (t - tt < T)\n                break;\n            if (memo[r][c]\
    \ != -1) {\n                // \u713C\u304D\u3042\u304C\u3063\u3066\u3044\u308B\
    \u304B\u3064\u305F\u3044\u713C\u304D\u304C\u3042\u308B\n                ft1.add(r,\
    \ c, -1);\n                ft0.add(r, c, 1);\n            }\n            q.pop();\n\
    \        }\n\n        if (c == 0) {\n            int h, w;\n            cin >>\
    \ h >> w;\n            h--, w--;\n            memo[h][w] = t;\n            ft1.add(h,\
    \ w, 1);\n            q.push(Pair(t, Pii(h, w)));\n        } else if (c == 1)\
    \ {\n            int h, w;\n            cin >> h >> w;\n            h--, w--;\n\
    \            if (ft0.sum(h, w, h + 1, w + 1) == 1) {\n                ft0.add(h,\
    \ w, -1);\n                memo[h][w] = -1;\n            }\n        } else if\
    \ (c == 2) {\n            int h1, w1, h2, w2;\n            cin >> h1 >> w1 >>\
    \ h2 >> w2;\n            h1--, w1--;\n            cout << ft0.sum(h1, w1, h2,\
    \ w2) << \" \" << ft1.sum(h1, w1, h2, w2) << endl;\n        }\n    }\n}\n\nint\
    \ main() {\n    int T = 1;\n    // cin>>T;\n    while (T--) {\n        solve();\n\
    \    }\n    return 0;\n}\n"
  code: "#include \"../template.hpp\"\n\n#include \"../structure/fenwick-tree2D.hpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \n\nvoid solve() {\n    int H, W, T, Q;\n    cin >> H >> W >> T >> Q;\n    fenwick_tree2D<int>\
    \ ft0(H, W); // \u3059\u3067\u306B\u713C\u304D\u3042\u304C\u3063\u305F\u305F\u3044\
    \u713C\u304D\n    fenwick_tree2D<int> ft1(H, W); // \u307E\u3060\u713C\u304D\u3042\
    \u304C\u3063\u3066\u3044\u306A\u3044\u305F\u3044\u713C\u304D\n    vvi memo(H,\
    \ vi(W, -1));\n    using Pair = pair<int, Pii>; // \u6642\u9593\u3068\u5EA7\u6A19\
    \n    priority_queue<Pair, vector<Pair>, greater<Pair>> q;\n    while (Q--) {\n\
    \        int t, c;\n        cin >> t >> c;\n        // \u305F\u3044\u713C\u304D\
    \u306E\u713C\u304D\u4E0A\u304C\u308A\u3092\u898B\u308B\n        while (!q.empty())\
    \ {\n            int tt = q.top().first;\n            auto [r, c] = q.top().second;\n\
    \            if (t - tt < T)\n                break;\n            if (memo[r][c]\
    \ != -1) {\n                // \u713C\u304D\u3042\u304C\u3063\u3066\u3044\u308B\
    \u304B\u3064\u305F\u3044\u713C\u304D\u304C\u3042\u308B\n                ft1.add(r,\
    \ c, -1);\n                ft0.add(r, c, 1);\n            }\n            q.pop();\n\
    \        }\n\n        if (c == 0) {\n            int h, w;\n            cin >>\
    \ h >> w;\n            h--, w--;\n            memo[h][w] = t;\n            ft1.add(h,\
    \ w, 1);\n            q.push(Pair(t, Pii(h, w)));\n        } else if (c == 1)\
    \ {\n            int h, w;\n            cin >> h >> w;\n            h--, w--;\n\
    \            if (ft0.sum(h, w, h + 1, w + 1) == 1) {\n                ft0.add(h,\
    \ w, -1);\n                memo[h][w] = -1;\n            }\n        } else if\
    \ (c == 2) {\n            int h1, w1, h2, w2;\n            cin >> h1 >> w1 >>\
    \ h2 >> w2;\n            h1--, w1--;\n            cout << ft0.sum(h1, w1, h2,\
    \ w2) << \" \" << ft1.sum(h1, w1, h2, w2) << endl;\n        }\n    }\n}\n\nint\
    \ main() {\n    int T = 1;\n    // cin>>T;\n    while (T--) {\n        solve();\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - template.hpp
  - structure/fenwick-tree2D.hpp
  isVerificationFile: true
  path: test-verify/fenwick-tree3.test.cpp
  requiredBy: []
  timestamp: '2024-12-26 13:41:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test-verify/fenwick-tree3.test.cpp
layout: document
redirect_from:
- /verify/test-verify/fenwick-tree3.test.cpp
- /verify/test-verify/fenwick-tree3.test.cpp.html
title: test-verify/fenwick-tree3.test.cpp
---
