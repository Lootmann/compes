#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do {cout << msg << endl;exit(0);} while (0)
#define el '\n'

#define all(k)  k.begin(), k.end()
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

struct P {
  int y;
  int x;
};

int dh[]{-1, 0, 0, 1};
int dw[]{0, -1, 1, 0};

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  vector dist(H, vector<int>(W, 0));

  auto bfs = [&](int sh, int sw) {
    dist[sh][sw] = 1;

    queue<P> que;
    que.push({sh, sw});

    while (!que.empty()) {
      auto [h, w] = que.front();
      que.pop();

      rep(k, 4) {
        int nh = h + dh[k];
        int nw = w + dw[k];

        if (!(0 <= nh && nh < H && 0 <= nw && nw < W)) continue;
        if (grid[nh][nw] == '#') continue;
        if (dist[nh][nw] != 0) continue;

        dist[nh][nw] = dist[h][w] + 1;
        que.push({nh, nw});
      }
    }
  };

  // found shorted path count
  bfs(0, 0);

  // can't goal
  if (dist[H - 1][W - 1] == 0) die(-1);

  // dist
  int shortest = dist[H - 1][W - 1];

  // find #
  int sharp{};
  rep(h, H) rep(w, W) {
    if (grid[h][w] == '#') sharp++;
  }

  out(H * W - sharp - shortest);
}
