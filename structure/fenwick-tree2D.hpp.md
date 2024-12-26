---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/fenwick-tree3.test.cpp
    title: test-verify/fenwick-tree3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/fenwick-tree2D.hpp\"\ntemplate <class T>\nstruct\
    \ fenwick_tree2D {\npublic:\n    fenwick_tree2D() : _h(0), _w(0) {}\n    explicit\
    \ fenwick_tree2D(int h, int w) : _h(h + 1), _w(w + 1), data(h + 1, vector<T>(w\
    \ + 1, 0)) {}\n\n    void add(int r, int c, T x) {\n        r++, c++; // 1-origin\u306B\
    \u5909\u63DB\n        for (int i = r; i < _h; i += (i & -i)) {\n            for\
    \ (int j = c; j < _w; j += (j & -j)) {\n                data[i][j] += x;\n   \
    \         }\n        }\n    }\n\n    T sum(int r, int c) {\n        T ret = 0;\n\
    \        // r++, c++; // 1-origin\u306B\u5909\u63DB r++,c++\n        // r--, c--;\
    \ // \u958B\u533A\u9593\u306B\u5909\u63DB r--,c-- ->\u3042\u308F\u305B\u308B\u3068\
    \u304B\u308F\u3089\u306A\u3044\n        for (int i = r; i > 0; i -= (i & -i))\
    \ {\n            for (int j = c; j > 0; j -= (j & -j)) {\n                ret\
    \ += data[i][j];\n            }\n        }\n        return ret;\n    }\n\n   \
    \ T sum(int r1, int c1, int r2, int c2) {\n        return +sum(r2, c2) + sum(r1,\
    \ c1) - sum(r1, c2) - sum(r2, c1);\n    }\n\nprivate:\n    int _h, _w;\n    vector<vector<T>>\
    \ data;\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct fenwick_tree2D {\npublic:\n    fenwick_tree2D()\
    \ : _h(0), _w(0) {}\n    explicit fenwick_tree2D(int h, int w) : _h(h + 1), _w(w\
    \ + 1), data(h + 1, vector<T>(w + 1, 0)) {}\n\n    void add(int r, int c, T x)\
    \ {\n        r++, c++; // 1-origin\u306B\u5909\u63DB\n        for (int i = r;\
    \ i < _h; i += (i & -i)) {\n            for (int j = c; j < _w; j += (j & -j))\
    \ {\n                data[i][j] += x;\n            }\n        }\n    }\n\n   \
    \ T sum(int r, int c) {\n        T ret = 0;\n        // r++, c++; // 1-origin\u306B\
    \u5909\u63DB r++,c++\n        // r--, c--; // \u958B\u533A\u9593\u306B\u5909\u63DB\
    \ r--,c-- ->\u3042\u308F\u305B\u308B\u3068\u304B\u308F\u3089\u306A\u3044\n   \
    \     for (int i = r; i > 0; i -= (i & -i)) {\n            for (int j = c; j >\
    \ 0; j -= (j & -j)) {\n                ret += data[i][j];\n            }\n   \
    \     }\n        return ret;\n    }\n\n    T sum(int r1, int c1, int r2, int c2)\
    \ {\n        return +sum(r2, c2) + sum(r1, c1) - sum(r1, c2) - sum(r2, c1);\n\
    \    }\n\nprivate:\n    int _h, _w;\n    vector<vector<T>> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/fenwick-tree2D.hpp
  requiredBy: []
  timestamp: '2024-12-26 13:41:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/fenwick-tree3.test.cpp
documentation_of: structure/fenwick-tree2D.hpp
layout: document
redirect_from:
- /library/structure/fenwick-tree2D.hpp
- /library/structure/fenwick-tree2D.hpp.html
title: structure/fenwick-tree2D.hpp
---
