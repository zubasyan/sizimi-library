---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  - icon: ':heavy_check_mark:'
    path: tree/DSU_W.hpp
    title: "\u5DEE\u5206\u5236\u7D04\u3092\u307F\u305F\u3059dsu"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test-verify/dsu_w.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#line 2 \"template.hpp\"\nusing namespace std;\nrandom_device seed_gen;\nmt19937\
    \ rnd(seed_gen());\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
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
    #define eb emplace_back\n#define pb push_back\n#line 2 \"tree/DSU_W.hpp\"\n/**\n\
    \ * @class DSU_W\n * @brief \u5DEE\u5206\u5236\u7D04\u3092\u307F\u305F\u3059dsu\n\
    \ */\ntemplate <class T>\nclass DSU_W {\nprivate:\n    vector<int> parents_; //\
    \ \u9802\u70B9i\u306E\u89AA\n    vector<int> size_;    // \u9802\u70B9i\u304C\u6240\
    \u5C5E\u3059\u308B\u6728\u306E\u30B5\u30A4\u30BA\n    vector<T> diff_;      //\
    \ \u6728\u306E\u6839\u304B\u3089\u9802\u70B9i\u3078\u306E\u5DEE\u5206\n    int\
    \ n_;\n\npublic:\n    DSU_W() = default;\n\n    /**\n     * @brief \u91CD\u307F\
    \u4ED8\u304Ddsu\u3092\u69CB\u7BC9\n     * @param n \u8981\u7D20\u6570\n     */\n\
    \    explicit DSU_W(size_t n)\n        : parents_(n), size_(n, 1), diff_(n), n_(n)\
    \ {\n        std::iota(parents_.begin(), parents_.end(), 0);\n    }\n\n    /**\n\
    \     * @brief leader(\u6839\u3092\u8FD4\u3059)\n     * @return \u6839\u306E\u9802\
    \u70B9\u756A\u53F7\n     */\n    int leader(int i) {\n        assert(0 <= i &&\
    \ i < n_);\n        if (parents_[i] == i)\n            return i;\n        const\
    \ int root = leader(parents_[i]);\n        diff_[i] += diff_[parents_[i]];\n \
    \       return parents_[i] = root;\n    };\n\n    /**\n     * @brief a,b\u3092\
    \u7D71\u5408\n     * @param a \u4E00\u65B9\u306E\u9802\u70B9\u756A\u53F7\n   \
    \  * @param b \u4ED6\u65B9\u306E\u9802\u70B9\u756A\u53F7\n     * @param w b\u306E\
    \u91CD\u307F\u3068a\u306E\u91CD\u307F\u306E\u5DEE\u3000w=w_b-w_a\n     * @return\
    \ T/F \u3059\u3067\u306B\u9023\u7D50\u304B\u3064\u5236\u7D04\u3092\u6E80\u305F\
    \u3059\u307E\u305F\u306F\u975E\u9023\u7D50\u306A\u3089true\n     */\n    bool\
    \ merge(int a, int b, T w) {\n        assert(0 <= a && a < n_);\n        assert(0\
    \ <= b && b < n_);\n        w += weight(a); // \u6839\u540C\u58EB\u306E\u5DEE\u5206\
    \u306B\u843D\u3068\u3059\u305F\u3081\n        w -= weight(b);\n\n        a = leader(a);\n\
    \        b = leader(b);\n        if (a == b) {\n            // \u9023\u7D50\u306A\
    \u3089\n            return diff(a, b) == w;\n        }\n        if (size_[a] <\
    \ size_[b]) {\n            swap(a, b), w = -w;\n        }\n        size_[a] +=\
    \ size_[b];\n        parents_[b] = a;\n        diff_[b] = w;\n        return true;\n\
    \    }\n    /**\n     * @brief a,b\u306E\u91CD\u307F\u306E\u5DEE\n     * @param\
    \ a \u4E00\u65B9\u306E\u9802\u70B9\u756A\u53F7\n     * @param b \u4ED6\u65B9\u306E\
    \u9802\u70B9\u756A\u53F7\n     * @return a,b\u306E\u91CD\u307F\u306E\u5DEE w_b-w_a\n\
    \     */\n    T diff(int a, int b) {\n        assert(0 <= a && a < n_);\n    \
    \    assert(0 <= b && b < n_);\n        return weight(b) - weight(a);\n    }\n\
    \    /**\n     * @brief a,b\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\
    \u3059\u304B\u5224\u5B9A\n     * @param a \u4E00\u65B9\u306E\u9802\u70B9\u756A\
    \u53F7\n     * @param b \u4ED6\u65B9\u306E\u9802\u70B9\u756A\u53F7\n     * @return\
    \ T/F\n     */\n    bool same(int a, int b) {\n        assert(0 <= a && a < n_);\n\
    \        assert(0 <= b && b < n_);\n        return (leader(a) == leader(b));\n\
    \    }\n\nprivate:\n    T weight(int i) {\n        assert(0 <= i && i < n_);\n\
    \        leader(i);\n        return diff_[i];\n    }\n};\n#line 5 \"test-verify/dsu_w.test.cpp\"\
    \nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    DSU_W<ll> uf(N);\n  \
    \  while (Q--) {\n        int op;\n        cin >> op;\n        if (op == 0) {\n\
    \            int x, y, z;\n            cin >> x >> y >> z;\n            uf.merge(x,\
    \ y, z);\n        } else if (op == 1) {\n            int x, y;\n            cin\
    \ >> x >> y;\n            if (uf.same(x, y))\n                cout << uf.diff(x,\
    \ y) << \"\\n\";\n            else\n                cout << \"?\\n\";\n      \
    \  } else {\n            cerr << \"error!\" << endl;\n            return;\n  \
    \      }\n    }\n}\n\nint main() {\n    // ios::sync_with_stdio(false);\n    //\
    \ std::cin.tie(nullptr);\n    int T = 1;\n    // cin>>T;\n    while (T--) {\n\
    \        solve();\n    }\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n#include \"../tree/DSU_W.hpp\"\nvoid solve() {\n    int N, Q;\n    cin >> N\
    \ >> Q;\n    DSU_W<ll> uf(N);\n    while (Q--) {\n        int op;\n        cin\
    \ >> op;\n        if (op == 0) {\n            int x, y, z;\n            cin >>\
    \ x >> y >> z;\n            uf.merge(x, y, z);\n        } else if (op == 1) {\n\
    \            int x, y;\n            cin >> x >> y;\n            if (uf.same(x,\
    \ y))\n                cout << uf.diff(x, y) << \"\\n\";\n            else\n \
    \               cout << \"?\\n\";\n        } else {\n            cerr << \"error!\"\
    \ << endl;\n            return;\n        }\n    }\n}\n\nint main() {\n    // ios::sync_with_stdio(false);\n\
    \    // std::cin.tie(nullptr);\n    int T = 1;\n    // cin>>T;\n    while (T--)\
    \ {\n        solve();\n    }\n    return 0;\n}"
  dependsOn:
  - tree/DSU_W.hpp
  - template.hpp
  isVerificationFile: true
  path: test-verify/dsu_w.test.cpp
  requiredBy: []
  timestamp: '2025-02-01 10:58:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test-verify/dsu_w.test.cpp
layout: document
redirect_from:
- /verify/test-verify/dsu_w.test.cpp
- /verify/test-verify/dsu_w.test.cpp.html
title: test-verify/dsu_w.test.cpp
---
