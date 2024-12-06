#include <bits/stdc++.h>
using namespace std;
vector<pair<char, int>> encode(const string &str) {
    int n = int(str.size());
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        while (r < n && str[l] == str[r])
            r++;
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}
string decode(const string &str) {
    int n = int(str.size());
    string ret = "";
    for (int l = 0; l < n;) {
        int r = l + 1;
        while (r < n && '0' <= str[r] && str[r] <= '9')
            r++;
        int num = stoi(str.substr(l + 1, r - l));
        for (int i = 0; i < num; i++) {
            ret.push_back(str[l]);
        }
        l = r;
    }
    return ret;
}
string decode(const vector<pair<char, int>> &code) {
    string ret = "";
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}