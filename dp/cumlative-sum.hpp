template <class T>
struct Cumulative_sum {
 public:
  Cumulative_sum() = default;
  explicit Cumulative_sum(int n) {
    _n = n + 1;
    _data.resize(_n, static_cast<T>(0));
  }
  explicit Cumulative_sum(const vector<T>& a) {
    _n = static_cast<int>(a.size() + 1);
    _data.push_back(static_cast<T>(0));
    for (int i = 0; i < static_cast<T>(a.size()); i++) {
      _data.push_back(a[i]);
    }
  }

  void set(int p, T x) {
    assert(0 <= p && p + 1 < _n);
    _data[p + 1] = x;
  }

  void build() {
    for (int i = 1; i < _n; i++) {
      _data[i] += _data[i - 1];
    }
  }

  T sum(int l, int r) {
    assert(0 <= l && l < _n);
    assert(0 <= r && r < _n);
    return _data[r] - _data[l];
  }

  void show() {
    for (int i = 1; i < _n; i++) {
      cout << _data[i] << " ";
    }
    cout << endl;
  }

 private:
  int _n;
  vector<T> _data;
};