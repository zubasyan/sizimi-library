---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    #define pb push_back\n#line 2 \"benri/tableDraw.hpp\"\n\nvoid tableDraw(vvi &table)\
    \ {\n    int N = int(table.size()), M = int(table[0].size());\n    printf(\"i\\\
    \\j |\");\n    rep(i, M) printf(\"[%2d]|\", i);\n    rep(i, N) {\n        printf(\"\
    \\n\");\n        rep(i, M + 1) printf(\"----|\");\n        printf(\"\\n\");\n\
    \        printf(\"[%2d]|\", i);\n        for (int j = 0; j < M; j++) {\n     \
    \       printf(\"%4d|\", table[i][j]);\n        }\n    }\n    printf(\"\\n\");\n\
    }\n"
  code: "#include \"../template.hpp\";\n\nvoid tableDraw(vvi &table) {\n    int N\
    \ = int(table.size()), M = int(table[0].size());\n    printf(\"i\\\\j |\");\n\
    \    rep(i, M) printf(\"[%2d]|\", i);\n    rep(i, N) {\n        printf(\"\\n\"\
    );\n        rep(i, M + 1) printf(\"----|\");\n        printf(\"\\n\");\n     \
    \   printf(\"[%2d]|\", i);\n        for (int j = 0; j < M; j++) {\n          \
    \  printf(\"%4d|\", table[i][j]);\n        }\n    }\n    printf(\"\\n\");\n}"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: benri/tableDraw.hpp
  requiredBy: []
  timestamp: '2025-02-10 12:10:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: benri/tableDraw.hpp
layout: document
redirect_from:
- /library/benri/tableDraw.hpp
- /library/benri/tableDraw.hpp.html
title: benri/tableDraw.hpp
---
