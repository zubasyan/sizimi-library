#include "../template.hpp"
/**
 * @class DSU_W
 * @brief 差分制約をみたすdsu
 */
template <class T>
class DSU_W {
private:
    vector<int> parents_; // 頂点iの親
    vector<int> size_;    // 頂点iが所属する木のサイズ
    vector<T> diff_;      // 木の根から頂点iへの差分
    int n_;

public:
    DSU_W() = default;

    /**
     * @brief 重み付きdsuを構築
     * @param n 要素数
     */
    explicit DSU_W(size_t n)
        : parents_(n), size_(n, 1), diff_(n), n_(n) {
        std::iota(parents_.begin(), parents_.end(), 0);
    }

    /**
     * @brief leader(根を返す)
     * @return 根の頂点番号
     */
    int leader(int i) {
        assert(0 <= i && i < n_);
        if (parents_[i] == i)
            return i;
        const int root = leader(parents_[i]);
        diff_[i] += diff_[parents_[i]];
        return parents_[i] = root;
    };

    /**
     * @brief a,bを統合
     * @param a 一方の頂点番号
     * @param b 他方の頂点番号
     * @param w bの重みとaの重みの差　w=w_b-w_a
     * @return T/F すでに連結かつ制約を満たすまたは非連結ならtrue
     */
    bool merge(int a, int b, T w) {
        assert(0 <= a && a < n_);
        assert(0 <= b && b < n_);
        w += weight(a); // 根同士の差分に落とすため
        w -= weight(b);

        a = leader(a);
        b = leader(b);
        if (a == b) {
            // 連結なら
            return diff(a, b) == w;
        }
        if (size_[a] < size_[b]) {
            swap(a, b), w = -w;
        }
        size_[a] += size_[b];
        parents_[b] = a;
        diff_[b] = w;
        return true;
    }
    /**
     * @brief a,bの重みの差
     * @param a 一方の頂点番号
     * @param b 他方の頂点番号
     * @return a,bの重みの差 w_b-w_a
     */
    T diff(int a, int b) {
        assert(0 <= a && a < n_);
        assert(0 <= b && b < n_);
        return weight(b) - weight(a);
    }
    /**
     * @brief a,bが同じグループに属すか判定
     * @param a 一方の頂点番号
     * @param b 他方の頂点番号
     * @return T/F
     */
    bool same(int a, int b) {
        assert(0 <= a && a < n_);
        assert(0 <= b && b < n_);
        return (leader(a) == leader(b));
    }

private:
    T weight(int i) {
        assert(0 <= i && i < n_);
        leader(i);
        return diff_[i];
    }
};
