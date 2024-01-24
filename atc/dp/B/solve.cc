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
#define INFL 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;
  int n, k;
  cin >> n >> k;

  vector<llint> hi(n);
  rep(i, n) cin >> hi[i];

  vector<llint> dp(n, INFL);
  dp[0] = 0;

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i - j >= 0) {
        chmin(dp[i], dp[i - j] + abs(hi[i] - hi[i - j]));
      }
    }
    dump(dp);
  }

  dump(dp);
  output(dp[n - 1]);
}
