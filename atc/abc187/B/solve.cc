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

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<pair<double, double>> vp;
  rep(i, n) {
    double x, y;
    cin >> x >> y;
    vp.push_back(make_pair(x, y));
  }

  int cnt{};

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double y = vp[i].second - vp[j].second;
      double x = vp[i].first - vp[j].first;
      double gradient = y / x;
      if (-1 <= gradient && gradient <= 1) cnt++;
    }
  }

  output(cnt);
}
