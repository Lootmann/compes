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
  int N, K;
  cin >> N >> K;

  vector<int> ai(N);
  rep(i, N) cin >> ai[i];

  vector<vector<bool>> dp(N + 1, vector<bool>(K + 1));
  dp[0][0] = true;

  for (int i = 0; i < N; ++i) {
    for (int k = 0; k <= K; ++k) {
      // すでに入ってる -> こんなことなくない？
      if (!dp[i][k]) continue;

      dp[i + 1][k] = true;
      // 重量を超えない
      if (k + ai[i] <= K) {
        // push based
        dp[i + 1][k + ai[i]] = true;
      }
    }
  }

  for (int k = K; k >= 0; --k) {
    if (dp[N][k]) {
      cout << dp[N][k] << ' ';
    }
  }
}
