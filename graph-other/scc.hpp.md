---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/scc.test.cpp
    title: test-verify/scc.test.cpp
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
    #define pb push_back\n#line 2 \"graph-other/scc.hpp\"\nstruct scc_graph {\npublic:\n\
    \    scc_graph() : _n(0) {}\n    explicit scc_graph(int n) : _n(n), G(n), rG(n),\
    \ used(n), cmp(n) {}\n    void add_edge(int from, int to) {\n        assert(0\
    \ <= from && from < _n);\n        assert(0 <= to && to < _n);\n        G[from].pb(to);\n\
    \        rG[to].pb(from);\n    }\n    void dfs(int v) { // v\u304B\u3089dfs\n\
    \        used[v] = true;\n        for (auto to : G[v]) {\n            if (!used[to])\n\
    \                dfs(to);\n        }\n        vs.push_back(v);\n    }\n    void\
    \ rdfs(int v, int k) { // \u9006\u8FBA\u3067v\u304B\u3089dfs\n        used[v]\
    \ = true;\n        cmp[v] = k;\n        for (auto to : rG[v]) {\n            if\
    \ (!used[to])\n                rdfs(to, k);\n        }\n    }\n    void scc()\
    \ { // scc\u3092\u69CB\u7BC9\n        used.assign(_n, 0);\n        vs.clear();\n\
    \        rep(i, _n) if (!used[i]) dfs(i);\n        used.assign(_n, 0);\n     \
    \   int k = 0;\n        for (int i = sz(vs) - 1; i >= 0; i--) {\n            if\
    \ (!used[vs[i]])\n                rdfs(vs[i], k++);\n        }\n    }\n\n    int\
    \ _n;\n    vvi G, rG; // \u8FBA\u3068\u9006\u8FBA\n    vi used;   // \u3059\u3067\
    \u306B\u8ABF\u3079\u305F\u304B\u3001\n    vi vs;     //    \u5E30\u308A\u304C\u3051\
    \u9806\n    vi cmp;    // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F \u3064\
    \u307E\u308A \u5F37\u9023\u7D50\u6210\u5206\u306E\u30B0\u30EB\u30FC\u30D7\u756A\
    \u53F7\n};\n"
  code: "#include \"../template.hpp\"\nstruct scc_graph {\npublic:\n    scc_graph()\
    \ : _n(0) {}\n    explicit scc_graph(int n) : _n(n), G(n), rG(n), used(n), cmp(n)\
    \ {}\n    void add_edge(int from, int to) {\n        assert(0 <= from && from\
    \ < _n);\n        assert(0 <= to && to < _n);\n        G[from].pb(to);\n     \
    \   rG[to].pb(from);\n    }\n    void dfs(int v) { // v\u304B\u3089dfs\n     \
    \   used[v] = true;\n        for (auto to : G[v]) {\n            if (!used[to])\n\
    \                dfs(to);\n        }\n        vs.push_back(v);\n    }\n    void\
    \ rdfs(int v, int k) { // \u9006\u8FBA\u3067v\u304B\u3089dfs\n        used[v]\
    \ = true;\n        cmp[v] = k;\n        for (auto to : rG[v]) {\n            if\
    \ (!used[to])\n                rdfs(to, k);\n        }\n    }\n    void scc()\
    \ { // scc\u3092\u69CB\u7BC9\n        used.assign(_n, 0);\n        vs.clear();\n\
    \        rep(i, _n) if (!used[i]) dfs(i);\n        used.assign(_n, 0);\n     \
    \   int k = 0;\n        for (int i = sz(vs) - 1; i >= 0; i--) {\n            if\
    \ (!used[vs[i]])\n                rdfs(vs[i], k++);\n        }\n    }\n\n    int\
    \ _n;\n    vvi G, rG; // \u8FBA\u3068\u9006\u8FBA\n    vi used;   // \u3059\u3067\
    \u306B\u8ABF\u3079\u305F\u304B\u3001\n    vi vs;     //    \u5E30\u308A\u304C\u3051\
    \u9806\n    vi cmp;    // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F \u3064\
    \u307E\u308A \u5F37\u9023\u7D50\u6210\u5206\u306E\u30B0\u30EB\u30FC\u30D7\u756A\
    \u53F7\n};"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph-other/scc.hpp
  requiredBy: []
  timestamp: '2024-12-26 21:12:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/scc.test.cpp
documentation_of: graph-other/scc.hpp
layout: document
redirect_from:
- /library/graph-other/scc.hpp
- /library/graph-other/scc.hpp.html
title: graph-other/scc.hpp
---
