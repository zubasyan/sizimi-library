#include <chrono>
/**
 * @class TK
 * @brief 時間を管理するクラス
 */
class TK {
private:
    std::chrono::high_resolution_clock::time_point start_time_;
    int64_t time_threshold_;

public:
    /**
     * @brief コンストラクタ生成時からの時間を計測
     * @param time_threshold 制限時間[ms]
     */
    TK(const int64_t &time_threshold)
        : start_time_(std::chrono::high_resolution_clock::now()),
          time_threshold_(time_threshold) {}

    /**
     * @brief 経過時間を計算
     * @return 経過時間
     */
    int64_t elapsed() {
        auto diff = std::chrono::high_resolution_clock::now() - this->start_time_;
        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
    }
    /**
     * @brief 制限時間を超えたか判定
     * @return (現在時刻 - 生成時刻 > 制限時間)?
     */
    bool isTO() {
        return elapsed() >= time_threshold_;
    }
};