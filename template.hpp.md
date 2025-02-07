---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph-other/scc.hpp
    title: graph-other/scc.hpp
  - icon: ':heavy_check_mark:'
    path: number-theory/eulers-phi-function.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: number-theory/extgcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  - icon: ':heavy_check_mark:'
    path: structure/sparse-table.hpp
    title: structure/sparse-table.hpp
  - icon: ':heavy_check_mark:'
    path: tree/DSU_W.hpp
    title: "\u5DEE\u5206\u5236\u7D04\u3092\u307F\u305F\u3059dsu"
  - icon: ':heavy_check_mark:'
    path: tree/lca_tree.hpp
    title: tree/lca_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/dsu_w.test.cpp
    title: test-verify/dsu_w.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/eulers-phi-function.test.cpp
    title: test-verify/eulers-phi-function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/extgcd.test.cpp
    title: test-verify/extgcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/fenwick-tree1.test.cpp
    title: test-verify/fenwick-tree1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/fenwick-tree2.test.cpp
    title: test-verify/fenwick-tree2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/fenwick-tree3.test.cpp
    title: test-verify/fenwick-tree3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/lca_tree_doubling.test.cpp
    title: test-verify/lca_tree_doubling.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/scc.test.cpp
    title: test-verify/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test-verify/sparse-table.test.cpp
    title: test-verify/sparse-table.test.cpp
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
    #define pb push_back\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nrandom_device seed_gen;\n\
    mt19937 rnd(seed_gen());\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using vi = vector<int>;\nusing vvi = vector<vi>;\nusing vvvi = vector<vvi>;\n\
    using vl = vector<ll>;\nusing vvl = vector<vl>;\nusing vvvl = vector<vvl>;\nusing\
    \ Pii = pair<int, int>;\nusing Pll = pair<ll, ll>;\nusing Pil = pair<int, ll>;\n\
    using Pli = pair<ll, int>;\ntemplate <typename T>\ninline bool chmax(T &a, T b)\
    \ {\n    return ((a < b) ? (a = b, true) : (false));\n}\ntemplate <typename T>\n\
    inline bool chmin(T &a, T b) {\n    return ((a > b) ? (a = b, true) : (false));\n\
    }\nbool eq(double a, double b) { return abs(a - b) < 0.0000001; }\nconst string\
    \ LRUD = \"LRUD\";\nconst int di4[4] = {0, 0, -1, 1}, dj4[4] = {-1, 1, 0, 0};\n\
    const int di8[8] = {0, 0, 1, 1, 1, -1, -1, -1},\n          dj8[8] = {1, -1, 0,\
    \ -1, 1, 0, -1, 1};\n\n#define rep(i, n) for (int i = 0; i < n; i++)\n#define\
    \ rep1(i, n) for (int i = 1; i <= n; i++)\n#define Rrep(i, n) for (int i = n -\
    \ 1; i >= 0; i--)\n#define Rrep1(i, n) for (int i = n; i > 0; i--)\n#define all(a)\
    \ a.begin(), a.end()\n#if __cplusplus >= 202003L\n#define sz(a) ssize(a)\n#else\n\
    #define sz(a) (a.size())\n#endif\n#define yesno(ans) cout << ((ans) ? \"Yes\\\
    n\" : \"No\\n\")\n#define YESNO(ans) cout << ((ans) ? \"YES\\n\" : \"NO\\n\")\n\
    #define INF ((ll)2e18)\n#define IINF ((int)(1e9 + 5e8))\nconst double PI = 3.1415926535897932384626;\n\
    #define eb emplace_back\n#define pb push_back\n"
  dependsOn: []
  isVerificationFile: false
  path: template.hpp
  requiredBy:
  - structure/sparse-table.hpp
  - graph-other/scc.hpp
  - number-theory/extgcd.hpp
  - number-theory/eulers-phi-function.hpp
  - tree/DSU_W.hpp
  - tree/lca_tree.hpp
  timestamp: '2024-12-26 21:12:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/eulers-phi-function.test.cpp
  - test-verify/dsu_w.test.cpp
  - test-verify/fenwick-tree2.test.cpp
  - test-verify/sparse-table.test.cpp
  - test-verify/lca_tree_doubling.test.cpp
  - test-verify/fenwick-tree1.test.cpp
  - test-verify/fenwick-tree3.test.cpp
  - test-verify/extgcd.test.cpp
  - test-verify/scc.test.cpp
documentation_of: template.hpp
layout: document
redirect_from:
- /library/template.hpp
- /library/template.hpp.html
title: template.hpp
---
