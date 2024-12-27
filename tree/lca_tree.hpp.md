---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/lca_tree_doubling.test.cpp
    title: test-verify/lca_tree_doubling.test.cpp
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
    #define pb push_back\n#line 2 \"tree/lca_tree.hpp\"\nstruct lca_tree {\n    lca_tree()\
    \ : _n(0) {}\n    lca_tree(int n) : _n(n), G(n) {}\n    void add_edge(int u, int\
    \ v) {\n        G[u].pb(v);\n        G[v].pb(u);\n    }\n    void dfs(int v, int\
    \ p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n        for (auto\
    \ to : G[v]) {\n            if (to != p)\n                dfs(to, v, d + 1);\n\
    \        }\n    }\n    void build() {\n        max_k = 0;\n        while ((1 <<\
    \ max_k) < _n)\n            max_k++;\n\n        max_k += 2; // \u5FF5\u306E\u305F\
    \u3081.exe\n        parent.assign(max_k, vi(_n, -1));\n        depth.assign(_n,\
    \ -1);\n\n        dfs(0, -1, 0); // parent,depth\u3092\u521D\u671F\u5316\n   \
    \     for (int k = 0; k + 1 < max_k; k++) {\n            for (int v = 0; v < _n;\
    \ v++) {\n                if (parent[k][v] < 0)\n                    parent[k\
    \ + 1][v] = -1;\n                else\n                    parent[k + 1][v] =\
    \ parent[k][parent[k][v]];\n            }\n        }\n    }\n    int lca(int u,\
    \ int v) { // \u9802\u70B9u,v\u306Elca\u3092\u6C42\u3081\u308B\n        if (depth[u]\
    \ > depth[v])\n            swap(u, v);\n        // u,v\u306E\u6DF1\u3055\u3092\
    \u540C\u3058\u306B\u3059\u308B\n        for (int k = 0; k < max_k; k++) {\n  \
    \          if ((depth[v] - depth[u]) >> k & 1) {\n                v = parent[k][v];\n\
    \            }\n        }\n        if (u == v)\n            return u;\n      \
    \  for (int k = max_k - 1; k >= 0; k--) {\n            if (parent[k][u] != parent[k][v])\
    \ {\n                u = parent[k][u];\n                v = parent[k][v];\n  \
    \          }\n        }\n        return parent[0][u];\n    }\n    int dist(int\
    \ u, int v) {\n        return depth[u] + depth[v] - depth[lca(u, v)] * 2;\n  \
    \  }\n    int _n;     // \u9802\u70B9\u6570\n    vvi G;      // \u6728(\u5411\u7121\
    \u8FBA)\n    vi depth;   // \u6839\u304B\u3089\u306E\u6DF1\u3055\n    vvi parent;\
    \ // \u89AA\u30922^k\u56DE\u305F\u3069\u3063\u3066\u5230\u9054\u3059\u308B\u9802\
    \u70B9(\u306A\u3044\u306A\u3089-1)\n    int max_k;\n};\n"
  code: "#include \"../template.hpp\"\nstruct lca_tree {\n    lca_tree() : _n(0) {}\n\
    \    lca_tree(int n) : _n(n), G(n) {}\n    void add_edge(int u, int v) {\n   \
    \     G[u].pb(v);\n        G[v].pb(u);\n    }\n    void dfs(int v, int p, int\
    \ d) {\n        parent[0][v] = p;\n        depth[v] = d;\n        for (auto to\
    \ : G[v]) {\n            if (to != p)\n                dfs(to, v, d + 1);\n  \
    \      }\n    }\n    void build() {\n        max_k = 0;\n        while ((1 <<\
    \ max_k) < _n)\n            max_k++;\n\n        max_k += 2; // \u5FF5\u306E\u305F\
    \u3081.exe\n        parent.assign(max_k, vi(_n, -1));\n        depth.assign(_n,\
    \ -1);\n\n        dfs(0, -1, 0); // parent,depth\u3092\u521D\u671F\u5316\n   \
    \     for (int k = 0; k + 1 < max_k; k++) {\n            for (int v = 0; v < _n;\
    \ v++) {\n                if (parent[k][v] < 0)\n                    parent[k\
    \ + 1][v] = -1;\n                else\n                    parent[k + 1][v] =\
    \ parent[k][parent[k][v]];\n            }\n        }\n    }\n    int lca(int u,\
    \ int v) { // \u9802\u70B9u,v\u306Elca\u3092\u6C42\u3081\u308B\n        if (depth[u]\
    \ > depth[v])\n            swap(u, v);\n        // u,v\u306E\u6DF1\u3055\u3092\
    \u540C\u3058\u306B\u3059\u308B\n        for (int k = 0; k < max_k; k++) {\n  \
    \          if ((depth[v] - depth[u]) >> k & 1) {\n                v = parent[k][v];\n\
    \            }\n        }\n        if (u == v)\n            return u;\n      \
    \  for (int k = max_k - 1; k >= 0; k--) {\n            if (parent[k][u] != parent[k][v])\
    \ {\n                u = parent[k][u];\n                v = parent[k][v];\n  \
    \          }\n        }\n        return parent[0][u];\n    }\n    int dist(int\
    \ u, int v) {\n        return depth[u] + depth[v] - depth[lca(u, v)] * 2;\n  \
    \  }\n    int _n;     // \u9802\u70B9\u6570\n    vvi G;      // \u6728(\u5411\u7121\
    \u8FBA)\n    vi depth;   // \u6839\u304B\u3089\u306E\u6DF1\u3055\n    vvi parent;\
    \ // \u89AA\u30922^k\u56DE\u305F\u3069\u3063\u3066\u5230\u9054\u3059\u308B\u9802\
    \u70B9(\u306A\u3044\u306A\u3089-1)\n    int max_k;\n};\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: tree/lca_tree.hpp
  requiredBy: []
  timestamp: '2024-12-27 16:41:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/lca_tree_doubling.test.cpp
documentation_of: tree/lca_tree.hpp
layout: document
redirect_from:
- /library/tree/lca_tree.hpp
- /library/tree/lca_tree.hpp.html
title: tree/lca_tree.hpp
---
