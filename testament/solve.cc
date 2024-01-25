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
#define INFi 1 << 30
#define INFll 1LL << 60

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

  vector<int> hi(n);
  rep(i, n) cin >> hi[i];

  vector<int> dp(n, INFi);
  dp[0] = 0;

  for (int i = 1; i < n; ++i) {
    dp[i] = min(dp[i], dp[i - 1] + abs(hi[i] - hi[i - 1]));

    if (i >= 2) {
      dp[i] = min(dp[i], dp[i - 2] + abs(hi[i] - hi[i - 2]));
    }
  }

  output(dp[n - 1]);
}
