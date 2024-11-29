---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/cumlative-sum.hpp
    title: dp/cumlative-sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test-verify/cumulative-sum.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#line 1 \"dp/cumlative-sum.hpp\"\ntemplate <class T>\nstruct Cumulative_sum\
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
    \    cout << endl;\n  }\n\n private:\n  int _n;\n  vector<T> _data;\n};\n#line\
    \ 5 \"test-verify/cumulative-sum.test.cpp\"\n\nint main() {\n  int N, Q;\n  cin\
    \ >> N >> Q;\n  Cumulative_sum<long long> cumsum(N);\n  for (int i = 0; i < N;\
    \ i++) {\n    int a;\n    cin >> a;\n    cumsum.set(i, a);\n  }\n  cumsum.build();\n\
    \  for (int qi = 0; qi < Q; qi++) {\n    int l, r;\n    cin >> l >> r;\n    cout\
    \ << cumsum.sum(l, r) << \"\\n\";\n  }\n  return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#include \"./../dp/cumlative-sum.hpp\"\n\nint main() {\n  int N, Q;\n  cin >>\
    \ N >> Q;\n  Cumulative_sum<long long> cumsum(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    int a;\n    cin >> a;\n    cumsum.set(i, a);\n  }\n  cumsum.build();\n\
    \  for (int qi = 0; qi < Q; qi++) {\n    int l, r;\n    cin >> l >> r;\n    cout\
    \ << cumsum.sum(l, r) << \"\\n\";\n  }\n  return 0;\n}"
  dependsOn:
  - dp/cumlative-sum.hpp
  isVerificationFile: true
  path: test-verify/cumulative-sum.test.cpp
  requiredBy: []
  timestamp: '2024-11-29 16:29:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test-verify/cumulative-sum.test.cpp
layout: document
redirect_from:
- /verify/test-verify/cumulative-sum.test.cpp
- /verify/test-verify/cumulative-sum.test.cpp.html
title: test-verify/cumulative-sum.test.cpp
---
