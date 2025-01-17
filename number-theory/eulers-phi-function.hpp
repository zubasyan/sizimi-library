#include "../template.hpp"
/**
 * @brief オイラーのφ関数
 * 正整数nについて、1からn以下の自然数のうちnと互いに素なものの個数
 * @date 2025/01/17
 * @param n 1<=n
 * @return n以下の自然数のうちnと互いに素なものの個数
 */
ll phi(ll n) {
    ll ret = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        ret -= ret / n;
    return ret;
}