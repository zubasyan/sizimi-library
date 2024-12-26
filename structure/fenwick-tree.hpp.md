---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/fenwick-tree1.test.cpp
    title: test-verify/fenwick-tree1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/fenwick-tree.hpp\"\ntemplate <class T>\nstruct\
    \ fenwick_tree {\npublic:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int\
    \ n) : _n(n + 1), data(n + 1, 0) {}\n\n    void add(int p, T x) {\n        assert(0\
    \ <= p && p < _n);\n        p++; // 1-origin\u306B\u5909\u63DB\n        while\
    \ (p < _n) {\n            data[p] += x;\n            p += p & -p;\n        }\n\
    \    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n\
    \        r++, l++; // 1-origin\u306B\u5909\u63DB\n        return sum(r - 1) -\
    \ sum(l - 1);\n    }\n\n    int lower_bound(T w) { // [0,x)\u03A3a_i >=w \u3068\
    \u306A\u308B\u6700\u5C0F\u306Ex (\u5916\u90E8\u306E\u6DFB\u3048\u5B57\u30670-origin)\n\
    \        if (w <= 0)\n            return 0;\n        else {\n            int x\
    \ = 0, r = 1;\n            while (r < _n)\n                r = r << 1;\n     \
    \       for (int len = r; len > 0; len = len >> 1) {\n                if (x +\
    \ len < _n && data[x + len] < w) {\n                    w -= data[x + len];\n\
    \                    x += len;\n                }\n            }\n           \
    \ return x + 1;\n        }\n    }\n\nprivate:\n    int _n;\n    vector<T> data;\n\
    \    T sum(int r) {\n        T ret = 0;\n        while (r > 0) {\n           \
    \ ret += data[r];\n            r -= r & -r;\n        }\n        return ret;\n\
    \    }\n};\n"
  code: "#pragma once\ntemplate <class T>\nstruct fenwick_tree {\npublic:\n    fenwick_tree()\
    \ : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n + 1), data(n + 1, 0) {}\n\
    \n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\
    \ // 1-origin\u306B\u5909\u63DB\n        while (p < _n) {\n            data[p]\
    \ += x;\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        r++, l++; // 1-origin\u306B\
    \u5909\u63DB\n        return sum(r - 1) - sum(l - 1);\n    }\n\n    int lower_bound(T\
    \ w) { // [0,x)\u03A3a_i >=w \u3068\u306A\u308B\u6700\u5C0F\u306Ex (\u5916\u90E8\
    \u306E\u6DFB\u3048\u5B57\u30670-origin)\n        if (w <= 0)\n            return\
    \ 0;\n        else {\n            int x = 0, r = 1;\n            while (r < _n)\n\
    \                r = r << 1;\n            for (int len = r; len > 0; len = len\
    \ >> 1) {\n                if (x + len < _n && data[x + len] < w) {\n        \
    \            w -= data[x + len];\n                    x += len;\n            \
    \    }\n            }\n            return x + 1;\n        }\n    }\n\nprivate:\n\
    \    int _n;\n    vector<T> data;\n    T sum(int r) {\n        T ret = 0;\n  \
    \      while (r > 0) {\n            ret += data[r];\n            r -= r & -r;\n\
    \        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2024-12-26 12:43:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/fenwick-tree1.test.cpp
documentation_of: structure/fenwick-tree.hpp
layout: document
redirect_from:
- /library/structure/fenwick-tree.hpp
- /library/structure/fenwick-tree.hpp.html
title: structure/fenwick-tree.hpp
---
