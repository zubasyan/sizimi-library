#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "./../dp/cumlative-sum.hpp"

int main() {
  int N, Q;
  cin >> N >> Q;
  Cumulative_sum<long long> cumsum(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    cumsum.set(i, a);
  }
  cumsum.build();
  for (int qi = 0; qi < Q; qi++) {
    int l, r;
    cin >> l >> r;
    cout << cumsum.sum(l, r) << "\n";
  }
  return 0;
}