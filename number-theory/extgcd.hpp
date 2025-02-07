#include "../template.hpp"
/**
 * @brief 拡張ユークリッドの互除法
 * @date 2025/02/06
 * @fn extgcd
 * @see 蟻本p109
 * @brief ax+by=gcd(a,b)の整数解(x,y)を求める
 * @param a,b 係数
 * @return (x,y,gcd(a,b))のtuple型
 * @test ../test-verify/extgcd.test.cpp
 */

tuple<ll, ll, ll> extgcd(ll a, ll b) {
    if (b != 0) {
        auto [y, x, d] = extgcd(b, a % b);
        y -= (a / b) * x;
        return {x, y, d};
    } else {
        return {1, 0, a};
    }
}