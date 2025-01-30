---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://cpprefjp.github.io/reference/random/uniform_real_distribution.html
  bundledCode: "#line 1 \"H/random.cpp\"\n#include <random>\n/**\n * @see https://cpprefjp.github.io/reference/random/uniform_real_distribution.html\n\
    \ */\nstd::random_device seed_gen;\nstd::default_random_engine engine(seed_gen);\n\
    using Random_int = std::uniform_int_distribution<int>;\nusing Random_double =\
    \ std::uniform_real_distribution<double>;\n"
  code: "#include <random>\n/**\n * @see https://cpprefjp.github.io/reference/random/uniform_real_distribution.html\n\
    \ */\nstd::random_device seed_gen;\nstd::default_random_engine engine(seed_gen);\n\
    using Random_int = std::uniform_int_distribution<int>;\nusing Random_double =\
    \ std::uniform_real_distribution<double>;\n"
  dependsOn: []
  isVerificationFile: false
  path: H/random.cpp
  requiredBy: []
  timestamp: '2025-01-30 21:41:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: H/random.cpp
layout: document
redirect_from:
- /library/H/random.cpp
- /library/H/random.cpp.html
title: H/random.cpp
---
