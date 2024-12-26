#include <bits/stdc++.h>
using namespace std;
random_device seed_gen;
mt19937 rnd(seed_gen());

using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using Pil = pair<int, ll>;
using Pli = pair<ll, int>;
template <typename T>
inline bool chmax(T &a, T b) {
    return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
    return ((a > b) ? (a = b, true) : (false));
}
bool eq(double a, double b) { return abs(a - b) < 0.0000001; }
const string LRUD = "LRUD";
const int di4[4] = {0, 0, -1, 1}, dj4[4] = {-1, 1, 0, 0};
const int di8[8] = {0, 0, 1, 1, 1, -1, -1, -1},
          dj8[8] = {1, -1, 0, -1, 1, 0, -1, 1};

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define Rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define Rrep1(i, n) for (int i = n; i > 0; i--)
#define all(a) a.begin(), a.end()
#if __cplusplus >= 202003L
#define sz(a) ssize(a)
#else
#define sz(a) (a.size())
#endif
#define yesno(ans) cout << ((ans) ? "Yes\n" : "No\n")
#define YESNO(ans) cout << ((ans) ? "YES\n" : "NO\n")
#define INF ((ll)2e18)
#define IINF ((int)(1e9 + 5e8))
const double PI = 3.1415926535897932384626;
#define eb emplace_back
#define pb push_back
