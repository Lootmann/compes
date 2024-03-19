#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

int main() {
  int N, K, D;
  cin >> N >> K >> D;

  vector<int> ai(N);
  rep(i, N) cin >> ai[i];

  vector dp(N + 1, vector(K + 1, vector<llint>(D, -1)));
  dp[0][0][0] = 0;

  rep(i, N) {
    rep(j, K + 1) {
      rep(k, D) {
        if (dp[i][j][k] == -1) continue;

        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);

        if (j != K) {
          chmax(dp[i + 1][j + 1][(k + ai[i]) % D], dp[i][j][k] + ai[i]);
        }
      }
    }
  }

  cout << dp[N][K][0] << el;
}
