#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
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

  int N{100};
  vector<vector<int>> nums(N + 1, vector<int>(N + 1, 0));

  rep(i, N) rep(j, i + 1) cin >> nums[i][j];

  vector<vector<int>> dp(N + 1, vector<int>(N, 0));
  dp[0][0] = nums[0][0];

  for (int i = 1; i < N; ++i) {
    chmax(dp[i][0], nums[i][0] + dp[i - 1][0]);

    for (int j = 1; j < i; ++j) {
      chmax(dp[i][j], nums[i][j] + dp[i - 1][j]);
      chmax(dp[i][j], nums[i][j] + dp[i - 1][j - 1]);
    }

    chmax(dp[i][i], nums[i][i] + dp[i - 1][i - 1]);
  }

  int sum{};
  for (int i = 0; i < 100; ++i) {
    chmax(sum, dp[N - 1][i]);
  }
  output(sum);
}
