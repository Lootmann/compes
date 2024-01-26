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
  // 1 <= N <= 100
  int N, W;
  cin >> N >> W;

  vector<llint> ws(N), vs(N);
  rep(i, N) cin >> ws[i] >> vs[i];

  // dp[value][total_weight]
  // 1 <= W <= 100000
  vector<vector<llint>> dp(N + 1, vector<llint>(100100));

  rep(i, N) {
    rep(sum_weight, W + 1) {
      // pick value[i], but can't over sum_weight
      if (sum_weight - ws[i] >= 0) {
        chmax(dp[i + 1][sum_weight], dp[i][sum_weight - ws[i]] + vs[i]);
      }

      // don't pick value[i]
      chmax(dp[i + 1][sum_weight], dp[i][sum_weight]);
    }
  }

  dump(dp[N][W]);
  output(dp[N][W]);
}
