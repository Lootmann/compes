#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

using llint = long long int;

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

int dh[]{-1, 1, -1, 1};
int dw[]{-1, -1, 1, 1};

void solve() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> grid(H, vector<int>(W, 0));
  rep(h, H) rep(w, W) cin >> grid[h][w];

  auto is_inbound = [&](int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
  };

  int maxv{};

  rep(h, H) rep(w, W) {
    int cur = grid[h][w];

    rep(i, 4) {
      int nh = h;
      int nw = w;

      while (true) {
        nh += dh[i];
        nw += dw[i];
        if (!is_inbound(nh, nw)) break;
        cur += grid[nh][nw];
      }
    }
    chmax(maxv, cur);
  }

  out(maxv);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
