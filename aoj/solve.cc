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
  int h, w;
  cin >> h >> w;

  vector<vector<int>> A(h, vector<int>(w, 0));
  vector<int> b(w, 0);

  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, w) cin >> b[i];

  rep(i, h) {
    int row{};
    rep(j, w) row += A[i][j] * b[j];
    output(row);
  }
}
