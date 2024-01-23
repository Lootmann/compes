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

  vector<llint> ai(n), bi(n), ci(n);
  rep(i, n) cin >> ai[i] >> bi[i] >> ci[i];
  dump(ai);
  dump(bi);
  dump(ci);

  // a, b, c
  vector<vector<llint>> dp(n + 1, vector<llint>(3, 0));

  // push-based
  for (int i = 0; i < n; ++i) {
    // (b,c) <- a
    chmax(dp[i + 1][1], dp[i][0] + ai[i]);
    chmax(dp[i + 1][2], dp[i][0] + ai[i]);

    // (a,c) <- b
    chmax(dp[i + 1][0], dp[i][1] + bi[i]);
    chmax(dp[i + 1][2], dp[i][1] + bi[i]);

    // (a,b) <- c
    chmax(dp[i + 1][0], dp[i][2] + ci[i]);
    chmax(dp[i + 1][1], dp[i][2] + ci[i]);
  }

  rep(i, n + 1) dump(dp[i]);
  output(max(dp[n][0], max(dp[n][1], dp[n][2])));
}
