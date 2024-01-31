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

  int H{20}, W{20};
  vector<vector<int>> grid(H, vector<int>(W, 0));

  rep(h, H) rep(w, W) {
    int a;
    cin >> a;
    grid[h][w] = a;
  }

  int ans{0};

  // horizontal
  rep(h, H) {
    rep(w, W - 3) {
      int cur{1};
      rep(k, 4) cur *= grid[h][w + k];
      chmax(ans, cur);
    }
  }
  dump(ans);

  // vertical
  rep(h, H - 3) {
    rep(w, W) {
      int cur{1};
      rep(k, 4) cur *= grid[h + k][w];
      chmax(ans, cur);
    }
  }
  dump(ans);

  // diagonal
  rep(h, H - 3) {
    rep(w, W - 3) {
      int cur{1};
      rep(k, 4) cur *= grid[h + k][w + k];
      chmax(ans, cur);
    }
  }
  dump(ans);

  rep(h, H - 3) {
    rep(w, W - 3) {
      int cur{1};
      rep(k, 4) cur *= grid[3 + h - k][w + k];
      chmax(ans, cur);
    }
  }
  dump(ans);

  output(ans);
}
