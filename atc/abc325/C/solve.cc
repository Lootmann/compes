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

int dh[]{-1, 0, 1, -1, 1, -1, 0, 1};
int dw[]{-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> grid(H);
  rep(h, H) cin >> grid[h];

  vector<vector<int>> dist(H, vector<int>(W, 0));

  auto dfs = [&](int sh, int sw, int id) {
    dist[sh][sw] = id;

    stack<pair<int, int>> st;
    st.push({sh, sw});

    while (!st.empty()) {
      auto [h, w] = st.top();
      st.pop();

      rep(k, 8) {
        int nh = h + dh[k];
        int nw = w + dw[k];

        if (!(0 <= nh && nh < H && 0 <= nw && nw < W)) continue;
        if (grid[nh][nw] != '#') continue;
        if (dist[nh][nw] != 0) continue;

        st.push({nh, nw});
        dist[nh][nw] = id;
      }
    }
  };

  int id{1};
  rep(h, H) rep(w, W) {
    if (grid[h][w] == '#' && dist[h][w] == 0) {
      dfs(h, w, id++);
    }
  }

  int ans{};
  rep(h, H) rep(w, W) chmax(ans, dist[h][w]);
  cout << ans << el;
}
