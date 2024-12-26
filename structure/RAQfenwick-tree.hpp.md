---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/fenwick-tree2.test.cpp
    title: test-verify/fenwick-tree2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/RAQfenwick-tree.hpp\"\ntemplate <class T>\nstruct\
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
    \    }\n};\n\ntemplate <class T>\nstruct RAQ {\npublic:\n    RAQ() : _n(0) {}\n\
    \    explicit RAQ(int n) : _n(n + 1),\n                          data0(n + 1),\n\
    \                          data1(n + 1) {}\n    void add(int p, T x) {\n     \
    \   assert(0 <= p && p < _n);\n        data0.add(p, x);\n    }\n    void add(int\
    \ l, int r, T x) {\n        assert(0 <= l && l <= r && r <= _n);\n        data0.add(l,\
    \ -x * l);\n        data1.add(l, x);\n        data0.add(r, x * r);\n        data1.add(r,\
    \ -x);\n    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        return sum(r) - sum(l);\n    }\n    T sum(int r) {\n    \
    \    assert(0 <= r && r <= _n);\n        //[0,r)\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B *(r-1) \u3067\u306F\u306A\u304F *r\u306B\u3063\u3066\u3044\u308B\u306E\
    \u306F\n        // a_0\u306E\u5BC4\u4E0E\u3092\u8003\u616E\u3059\u308B\u305F\u3081\
    \n        return data1.sum(0, r) * r + data0.sum(0, r);\n    }\n    T get(int\
    \ p) {\n        assert(0 <= p && p < _n);\n        return sum(p, p + 1);\n   \
    \ }\n\nprivate:\n    int _n;\n    fenwick_tree<T> data0, data1;\n};\n"
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
    \        }\n        return ret;\n    }\n};\n\ntemplate <class T>\nstruct RAQ {\n\
    public:\n    RAQ() : _n(0) {}\n    explicit RAQ(int n) : _n(n + 1),\n        \
    \                  data0(n + 1),\n                          data1(n + 1) {}\n\
    \    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        data0.add(p,\
    \ x);\n    }\n    void add(int l, int r, T x) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        data0.add(l, -x * l);\n        data1.add(l, x);\n  \
    \      data0.add(r, x * r);\n        data1.add(r, -x);\n    }\n\n    T sum(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r)\
    \ - sum(l);\n    }\n    T sum(int r) {\n        assert(0 <= r && r <= _n);\n \
    \       //[0,r)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B *(r-1) \u3067\u306F\u306A\
    \u304F *r\u306B\u3063\u3066\u3044\u308B\u306E\u306F\n        // a_0\u306E\u5BC4\
    \u4E0E\u3092\u8003\u616E\u3059\u308B\u305F\u3081\n        return data1.sum(0,\
    \ r) * r + data0.sum(0, r);\n    }\n    T get(int p) {\n        assert(0 <= p\
    \ && p < _n);\n        return sum(p, p + 1);\n    }\n\nprivate:\n    int _n;\n\
    \    fenwick_tree<T> data0, data1;\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/RAQfenwick-tree.hpp
  requiredBy: []
  timestamp: '2024-12-26 11:54:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/fenwick-tree2.test.cpp
documentation_of: structure/RAQfenwick-tree.hpp
layout: document
redirect_from:
- /library/structure/RAQfenwick-tree.hpp
- /library/structure/RAQfenwick-tree.hpp.html
title: structure/RAQfenwick-tree.hpp
---
