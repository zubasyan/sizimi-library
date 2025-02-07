#include "../number-theory/extgcd.hpp"
#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=ja"

int main() {
    int a, b;
    cin >> a >> b;
    auto [x, y, d] = extgcd(a, b);
    cout << x << " " << y << endl;
    return 0;
}
