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

  int N, M;
  cin >> N >> M;

  vector<vector<int>> ai(N, vector<int>(M, 0));
  rep(n, N) rep(m, M) cin >> ai[n][m];

  llint sum{};

  for (int i = 0; i < M; ++i) {
    for (int j = i + 1; j < M; ++j) {
      llint cur{};
      rep(n, N) {
        cur += max(ai[n][i], ai[n][j]);
      }
      chmax(sum, cur);
    }
  }

  output(sum);
}
