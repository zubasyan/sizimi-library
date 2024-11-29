---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/cumulative-sum.test.cpp
    title: test-verify/cumulative-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/cumlative-sum.hpp\"\ntemplate <class T>\nstruct Cumulative_sum\
    \ {\n public:\n  Cumulative_sum() = default;\n  explicit Cumulative_sum(int n)\
    \ {\n    _n = n + 1;\n    _data.resize(_n, static_cast<T>(0));\n  }\n  explicit\
    \ Cumulative_sum(const vector<T>& a) {\n    _n = static_cast<int>(a.size() + 1);\n\
    \    _data.push_back(static_cast<T>(0));\n    for (int i = 0; i < static_cast<T>(a.size());\
    \ i++) {\n      _data.push_back(a[i]);\n    }\n  }\n\n  void set(int p, T x) {\n\
    \    assert(0 <= p && p + 1 < _n);\n    _data[p + 1] = x;\n  }\n\n  void build()\
    \ {\n    for (int i = 1; i < _n; i++) {\n      _data[i] += _data[i - 1];\n   \
    \ }\n  }\n\n  T sum(int l, int r) {\n    assert(0 <= l && l < _n);\n    assert(0\
    \ <= r && r < _n);\n    return _data[r] - _data[l];\n  }\n\n  void show() {\n\
    \    for (int i = 1; i < _n; i++) {\n      cout << _data[i] << \" \";\n    }\n\
    \    cout << endl;\n  }\n\n private:\n  int _n;\n  vector<T> _data;\n};\n"
  code: "template <class T>\nstruct Cumulative_sum {\n public:\n  Cumulative_sum()\
    \ = default;\n  explicit Cumulative_sum(int n) {\n    _n = n + 1;\n    _data.resize(_n,\
    \ static_cast<T>(0));\n  }\n  explicit Cumulative_sum(const vector<T>& a) {\n\
    \    _n = static_cast<int>(a.size() + 1);\n    _data.push_back(static_cast<T>(0));\n\
    \    for (int i = 0; i < static_cast<T>(a.size()); i++) {\n      _data.push_back(a[i]);\n\
    \    }\n  }\n\n  void set(int p, T x) {\n    assert(0 <= p && p + 1 < _n);\n \
    \   _data[p + 1] = x;\n  }\n\n  void build() {\n    for (int i = 1; i < _n; i++)\
    \ {\n      _data[i] += _data[i - 1];\n    }\n  }\n\n  T sum(int l, int r) {\n\
    \    assert(0 <= l && l < _n);\n    assert(0 <= r && r < _n);\n    return _data[r]\
    \ - _data[l];\n  }\n\n  void show() {\n    for (int i = 1; i < _n; i++) {\n  \
    \    cout << _data[i] << \" \";\n    }\n    cout << endl;\n  }\n\n private:\n\
    \  int _n;\n  vector<T> _data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: dp/cumlative-sum.hpp
  requiredBy: []
  timestamp: '2024-11-29 16:29:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/cumulative-sum.test.cpp
documentation_of: dp/cumlative-sum.hpp
layout: document
redirect_from:
- /library/dp/cumlative-sum.hpp
- /library/dp/cumlative-sum.hpp.html
title: dp/cumlative-sum.hpp
---
