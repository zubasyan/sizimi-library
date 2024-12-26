---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"compression/run-length-encoding.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\nvector<pair<char, int>> encode(const string &str) {\n  \
    \  int n = int(str.size());\n    vector<pair<char, int>> ret;\n    for (int l\
    \ = 0; l < n;) {\n        int r = l + 1;\n        while (r < n && str[l] == str[r])\n\
    \            r++;\n        ret.push_back({str[l], r - l});\n        l = r;\n \
    \   }\n    return ret;\n}\nstring decode(const string &str) {\n    int n = int(str.size());\n\
    \    string ret = \"\";\n    for (int l = 0; l < n;) {\n        int r = l + 1;\n\
    \        while (r < n && '0' <= str[r] && str[r] <= '9')\n            r++;\n \
    \       int num = stoi(str.substr(l + 1, r - l));\n        for (int i = 0; i <\
    \ num; i++) {\n            ret.push_back(str[l]);\n        }\n        l = r;\n\
    \    }\n    return ret;\n}\nstring decode(const vector<pair<char, int>> &code)\
    \ {\n    string ret = \"\";\n    for (auto p : code) {\n        for (int i = 0;\
    \ i < p.second; i++) {\n            ret.push_back(p.first);\n        }\n    }\n\
    \    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nvector<pair<char, int>> encode(const\
    \ string &str) {\n    int n = int(str.size());\n    vector<pair<char, int>> ret;\n\
    \    for (int l = 0; l < n;) {\n        int r = l + 1;\n        while (r < n &&\
    \ str[l] == str[r])\n            r++;\n        ret.push_back({str[l], r - l});\n\
    \        l = r;\n    }\n    return ret;\n}\nstring decode(const string &str) {\n\
    \    int n = int(str.size());\n    string ret = \"\";\n    for (int l = 0; l <\
    \ n;) {\n        int r = l + 1;\n        while (r < n && '0' <= str[r] && str[r]\
    \ <= '9')\n            r++;\n        int num = stoi(str.substr(l + 1, r - l));\n\
    \        for (int i = 0; i < num; i++) {\n            ret.push_back(str[l]);\n\
    \        }\n        l = r;\n    }\n    return ret;\n}\nstring decode(const vector<pair<char,\
    \ int>> &code) {\n    string ret = \"\";\n    for (auto p : code) {\n        for\
    \ (int i = 0; i < p.second; i++) {\n            ret.push_back(p.first);\n    \
    \    }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: compression/run-length-encoding.hpp
  requiredBy: []
  timestamp: '2024-12-06 16:25:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: compression/run-length-encoding.hpp
layout: document
redirect_from:
- /library/compression/run-length-encoding.hpp
- /library/compression/run-length-encoding.hpp.html
title: compression/run-length-encoding.hpp
---
