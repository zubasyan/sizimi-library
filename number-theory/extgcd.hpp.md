---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test-verify/extgcd.test.cpp
    title: test-verify/extgcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5"
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
    #define pb push_back\n#line 2 \"number-theory/extgcd.hpp\"\n/**\n * @brief \u62E1\
    \u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n * @date 2025/02/06\n\
    \ * @fn extgcd\n * @see \u87FB\u672Cp109\n * @brief ax+by=gcd(a,b)\u306E\u6574\
    \u6570\u89E3(x,y)\u3092\u6C42\u3081\u308B\n * @param a,b \u4FC2\u6570\n * @return\
    \ (x,y,gcd(a,b))\u306Etuple\u578B\n * @test ../test-verify/extgcd.test.cpp\n */\n\
    \ntuple<ll, ll, ll> extgcd(ll a, ll b) {\n    if (b != 0) {\n        auto [y,\
    \ x, d] = extgcd(b, a % b);\n        y -= (a / b) * x;\n        return {x, y,\
    \ d};\n    } else {\n        return {1, 0, a};\n    }\n}\n"
  code: "#include \"../template.hpp\"\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\
    \u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n * @date 2025/02/06\n * @fn extgcd\n\
    \ * @see \u87FB\u672Cp109\n * @brief ax+by=gcd(a,b)\u306E\u6574\u6570\u89E3(x,y)\u3092\
    \u6C42\u3081\u308B\n * @param a,b \u4FC2\u6570\n * @return (x,y,gcd(a,b))\u306E\
    tuple\u578B\n * @test ../test-verify/extgcd.test.cpp\n */\n\ntuple<ll, ll, ll>\
    \ extgcd(ll a, ll b) {\n    if (b != 0) {\n        auto [y, x, d] = extgcd(b,\
    \ a % b);\n        y -= (a / b) * x;\n        return {x, y, d};\n    } else {\n\
    \        return {1, 0, a};\n    }\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: number-theory/extgcd.hpp
  requiredBy: []
  timestamp: '2025-02-07 11:37:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test-verify/extgcd.test.cpp
documentation_of: number-theory/extgcd.hpp
layout: document
redirect_from:
- /library/number-theory/extgcd.hpp
- /library/number-theory/extgcd.hpp.html
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---
