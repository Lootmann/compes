#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define INTi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

set<llint> factors(llint n) {
  set<llint> res;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.insert(i);
      res.insert(n / i);
    }
  }
  return res;
}

int main() {
  FastIO;
  llint n;
  cin >> n;

  vector<llint> hi(n);
  rep(i, n) cin >> hi[i];

  vector<llint> peaks(n);
  for (int i = 1; i < n - 1; ++i) {
    if (hi[i - 1] < hi[i] && hi[i] > hi[i + 1]) {
      peaks[i]++;
    }
  }

  vector<llint> acc(n + 1, 0);
  for (int i = 1; i < n; ++i) {
    acc[i + 1] += acc[i] + peaks[i];
  }

  llint max_day{};

  for (auto day_range : factors(n)) {
    bool good_range{true};

    for (int i = 0; i < n / day_range; ++i) {
      llint left = i * day_range;
      llint right = (i + 1) * day_range;
      llint num_peaks = acc[right] - acc[left];

      if (num_peaks == 0) {
        good_range = false;
        break;
      }
    }

    if (good_range) {
      chmax(max_day, n / day_range);
    }
  }

  output(max_day);
}
