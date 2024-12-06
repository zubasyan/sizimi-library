---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: compression/run-length-encoding.hpp
    title: compression/run-length-encoding.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1469
    links:
    - https://yukicoder.me/problems/no/1469
  bundledCode: "#line 1 \"test-verify/run-length-encode.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define PROBLEM \"https://yukicoder.me/problems/no/1469\"\
    \n#line 2 \"compression/run-length-encoding.hpp\"\nusing namespace std;\nvector<pair<char,\
    \ int>> encode(const string &str) {\n    int n = int(str.size());\n    vector<pair<char,\
    \ int>> ret;\n    for (int l = 0; l < n;) {\n        int r = l + 1;\n        while\
    \ (r < n && str[l] == str[r])\n            r++;\n        ret.push_back({str[l],\
    \ r - l});\n        l = r;\n    }\n    return ret;\n}\nstring decode(const string\
    \ &str) {\n    int n = int(str.size());\n    string ret = \"\";\n    for (int\
    \ l = 0; l < n;) {\n        int r = l + 1;\n        while (r < n && '0' <= str[r]\
    \ && str[r] <= '9')\n            r++;\n        int num = stoi(str.substr(l + 1,\
    \ r - l));\n        for (int i = 0; i < num; i++) {\n            ret.push_back(str[l]);\n\
    \        }\n        l = r;\n    }\n    return ret;\n}\nstring decode(const vector<pair<char,\
    \ int>> &code) {\n    string ret = \"\";\n    for (auto p : code) {\n        for\
    \ (int i = 0; i < p.second; i++) {\n            ret.push_back(p.first);\n    \
    \    }\n    }\n    return ret;\n}\n#line 5 \"test-verify/run-length-encode.test.cpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    for (auto [c, num] : encode(s))\
    \ {\n        cout << c;\n    }\n    cout << endl;\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#define PROBLEM \"https://yukicoder.me/problems/no/1469\"\
    \n#include \"./../compression/run-length-encoding.hpp\"\n\nint main() {\n    string\
    \ s;\n    cin >> s;\n    for (auto [c, num] : encode(s)) {\n        cout << c;\n\
    \    }\n    cout << endl;\n    return 0;\n}"
  dependsOn:
  - compression/run-length-encoding.hpp
  isVerificationFile: true
  path: test-verify/run-length-encode.test.cpp
  requiredBy: []
  timestamp: '2024-12-06 16:25:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test-verify/run-length-encode.test.cpp
layout: document
redirect_from:
- /verify/test-verify/run-length-encode.test.cpp
- /verify/test-verify/run-length-encode.test.cpp.html
title: test-verify/run-length-encode.test.cpp
---
