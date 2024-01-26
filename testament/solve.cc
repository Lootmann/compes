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
  int N;
  cin >> N;

  vector<int> ai(N, 0), bi(N, 0), ci(N, 0);
  rep(i, N) cin >> ai[i] >> bi[i] >> ci[i];

  vector<vector<int>> dp(N + 1, vector<int>(3, 0));

  for (int i = 1; i <= N; ++i) {
    // a <- b,c
    chmax(dp[i][0], dp[i - 1][1] + bi[i - 1]);
    chmax(dp[i][0], dp[i - 1][2] + ci[i - 1]);

    // b <- c,a
    chmax(dp[i][1], dp[i - 1][2] + ci[i - 1]);
    chmax(dp[i][1], dp[i - 1][0] + ai[i - 1]);

    // c <- a,b
    chmax(dp[i][2], dp[i - 1][0] + ai[i - 1]);
    chmax(dp[i][2], dp[i - 1][1] + bi[i - 1]);
  }

  int ans{};
  rep(i, 3) chmax(ans, dp[N][i]);
  output(ans);
}
