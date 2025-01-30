---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6642\u9593\u3092\u7BA1\u7406\u3059\u308B\u30AF\u30E9\u30B9"
    links: []
  bundledCode: "#line 1 \"H/time_keeper.cpp\"\n#include <chrono>\n/**\n * @class TK\n\
    \ * @brief \u6642\u9593\u3092\u7BA1\u7406\u3059\u308B\u30AF\u30E9\u30B9\n */\n\
    class TK {\nprivate:\n    std::chrono::high_resolution_clock::time_point start_time_;\n\
    \    int64_t time_threshold_;\n\npublic:\n    /**\n     * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u751F\u6210\u6642\u304B\u3089\u306E\u6642\u9593\u3092\
    \u8A08\u6E2C\n     * @param time_threshold \u5236\u9650\u6642\u9593[ms]\n    \
    \ */\n    TK(const int64_t &time_threshold)\n        : start_time_(std::chrono::high_resolution_clock::now()),\n\
    \          time_threshold_(time_threshold) {}\n\n    /**\n     * @brief \u7D4C\
    \u904E\u6642\u9593\u3092\u8A08\u7B97\n     * @return \u7D4C\u904E\u6642\u9593\n\
    \     */\n    int64_t elapsed() {\n        auto diff = std::chrono::high_resolution_clock::now()\
    \ - this->start_time_;\n        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();\n\
    \    }\n    /**\n     * @brief \u5236\u9650\u6642\u9593\u3092\u8D85\u3048\u305F\
    \u304B\u5224\u5B9A\n     * @return (\u73FE\u5728\u6642\u523B - \u751F\u6210\u6642\
    \u523B > \u5236\u9650\u6642\u9593)?\n     */\n    bool isTO() {\n        return\
    \ elapsed() >= time_threshold_;\n    }\n};\n"
  code: "#include <chrono>\n/**\n * @class TK\n * @brief \u6642\u9593\u3092\u7BA1\u7406\
    \u3059\u308B\u30AF\u30E9\u30B9\n */\nclass TK {\nprivate:\n    std::chrono::high_resolution_clock::time_point\
    \ start_time_;\n    int64_t time_threshold_;\n\npublic:\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u751F\u6210\u6642\u304B\u3089\u306E\
    \u6642\u9593\u3092\u8A08\u6E2C\n     * @param time_threshold \u5236\u9650\u6642\
    \u9593[ms]\n     */\n    TK(const int64_t &time_threshold)\n        : start_time_(std::chrono::high_resolution_clock::now()),\n\
    \          time_threshold_(time_threshold) {}\n\n    /**\n     * @brief \u7D4C\
    \u904E\u6642\u9593\u3092\u8A08\u7B97\n     * @return \u7D4C\u904E\u6642\u9593\n\
    \     */\n    int64_t elapsed() {\n        auto diff = std::chrono::high_resolution_clock::now()\
    \ - this->start_time_;\n        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();\n\
    \    }\n    /**\n     * @brief \u5236\u9650\u6642\u9593\u3092\u8D85\u3048\u305F\
    \u304B\u5224\u5B9A\n     * @return (\u73FE\u5728\u6642\u523B - \u751F\u6210\u6642\
    \u523B > \u5236\u9650\u6642\u9593)?\n     */\n    bool isTO() {\n        return\
    \ elapsed() >= time_threshold_;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: H/time_keeper.cpp
  requiredBy: []
  timestamp: '2025-01-30 21:41:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: H/time_keeper.cpp
layout: document
redirect_from:
- /library/H/time_keeper.cpp
- /library/H/time_keeper.cpp.html
title: "\u6642\u9593\u3092\u7BA1\u7406\u3059\u308B\u30AF\u30E9\u30B9"
---
