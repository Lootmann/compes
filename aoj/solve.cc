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
  int H, W;
  cin >> H >> W;

  vector<vector<int>> sheet(H + 1, vector<int>(W + 1, 0));
  rep(h, H) rep(w, W) cin >> sheet[h][w];

  rep(h, H) {
    int row_sum{};
    rep(w, W) row_sum += sheet[h][w];
    sheet[h][W] = row_sum;
  }

  rep(w, W) {
    int col_sum{};
    rep(h, H) col_sum += sheet[h][w];
    sheet[H][w] = col_sum;
  }

  rep(w, W) {
    int total_sum{};
    rep(h, H) total_sum += sheet[h][W];
    sheet[H][W] = total_sum;
  }

  rep(h, H + 1) {
    rep(w, W + 1) {
      cout << sheet[h][w] << (w == W ? '\n' : ' ');
    }
  }
}
