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

using Graph = vector<vector<int>>;
using vvb = vector<vector<bool>>;

int dh[]{-1, 0, 0, 1};
int dw[]{0, -1, 1, 0};

int main() {
  int H, W;
  cin >> W >> H;

  Graph graph(H, vector<int>(W, 0));
  rep(h, H) rep(w, W) cin >> graph[h][w];

  vvb visited(H, vector<bool>(W, false));

  int max_depth{};

  auto dfs = [&](auto f, int h, int w, int depth) -> void {
    graph[h][w] = 0;

    rep(k, 4) {
      int nh = h + dh[k];
      int nw = w + dw[k];

      if (!(0 <= nh && nh < H && 0 <= nw && nw < W)) continue;
      if (graph[nh][nw] == 0) continue;

      f(f, nh, nw, depth + 1);
    }

    graph[h][w] = 1;
    chmax(max_depth, depth);
  };

  rep(h, H) rep(w, W) {
    if (graph[h][w] == 1) {
      dfs(dfs, h, w, 1);
    }
  }
  out(max_depth);
}
