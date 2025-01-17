---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/eulers-phi-function.test.cpp
    title: test-verify/eulers-phi-function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570"
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
    #define pb push_back\n#line 2 \"number-theory/eulers-phi-function.hpp\"\n/**\n\
    \ * @brief \u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570\n * \u6B63\u6574\u6570\
    n\u306B\u3064\u3044\u3066\u30011\u304B\u3089n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\
    \u306E\u3046\u3061n\u3068\u4E92\u3044\u306B\u7D20\u306A\u3082\u306E\u306E\u500B\
    \u6570\n * @date 2025/01/17\n * @param n 1<=n\n * @return n\u4EE5\u4E0B\u306E\u81EA\
    \u7136\u6570\u306E\u3046\u3061n\u3068\u4E92\u3044\u306B\u7D20\u306A\u3082\u306E\
    \u306E\u500B\u6570\n */\nll phi(ll n) {\n    ll ret = n;\n    for (ll i = 2; i\
    \ * i <= n; i++) {\n        if (n % i == 0) {\n            ret -= ret / i;\n \
    \           while (n % i == 0)\n                n /= i;\n        }\n    }\n  \
    \  if (n > 1)\n        ret -= ret / n;\n    return ret;\n}\n"
  code: "#include \"../template.hpp\"\n/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E\
    \u03C6\u95A2\u6570\n * \u6B63\u6574\u6570n\u306B\u3064\u3044\u3066\u30011\u304B\
    \u3089n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\u306E\u3046\u3061n\u3068\u4E92\u3044\
    \u306B\u7D20\u306A\u3082\u306E\u306E\u500B\u6570\n * @date 2025/01/17\n * @param\
    \ n 1<=n\n * @return n\u4EE5\u4E0B\u306E\u81EA\u7136\u6570\u306E\u3046\u3061n\u3068\
    \u4E92\u3044\u306B\u7D20\u306A\u3082\u306E\u306E\u500B\u6570\n */\nll phi(ll n)\
    \ {\n    ll ret = n;\n    for (ll i = 2; i * i <= n; i++) {\n        if (n % i\
    \ == 0) {\n            ret -= ret / i;\n            while (n % i == 0)\n     \
    \           n /= i;\n        }\n    }\n    if (n > 1)\n        ret -= ret / n;\n\
    \    return ret;\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: number-theory/eulers-phi-function.hpp
  requiredBy: []
  timestamp: '2025-01-17 22:01:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/eulers-phi-function.test.cpp
documentation_of: number-theory/eulers-phi-function.hpp
layout: document
redirect_from:
- /library/number-theory/eulers-phi-function.hpp
- /library/number-theory/eulers-phi-function.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570"
---
