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
  int N, M, L;
  cin >> N >> M >> L;

  vector<vector<llint>> A(N, vector<llint>(M, 0)), B(M, vector<llint>(L, 0));
  rep(n, N) rep(m, M) cin >> A[n][m];
  rep(m, M) rep(l, L) cin >> B[m][l];

  rep(i, N) {
    rep(j, L) {
      llint c{};
      rep(k, M) c += A[i][k] * B[k][j];
      cout << c << (j == L - 1 ? '\n' : ' ');
    }
  }
}
