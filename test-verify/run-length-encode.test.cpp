#include <bits/stdc++.h>
using namespace std;
#define PROBLEM "https://yukicoder.me/problems/no/1469"
#include "./../compression/run-length-encoding.hpp"

int main() {
    string s;
    cin >> s;
    for (auto [c, num] : encode(s)) {
        cout << c;
    }
    cout << endl;
    return 0;
}