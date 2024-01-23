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
const llint INF = 1LL << 60;

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<llint> hi(n);
  rep(i, n) cin >> hi[i];

  vector<llint> dp(n, INF);
  dp[0] = 0;

  for (int i = 1; i < n; ++i) {
    if (i >= 1) {
      chmin(dp[i], dp[i - 1] + abs(hi[i] - hi[i - 1]));
    }
    if (i >= 2) {
      chmin(dp[i], dp[i - 2] + abs(hi[i] - hi[i - 2]));
    }
    dump(dp);
  }

  dump(dp);
  output(dp[n - 1]);
}
