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

using vvb = vector<vector<bool>>;
using vs = vector<string>;
using ci = const int;

int dh[]{-1, 0, 1, -1, 1, -1, 0, 1};
int dw[]{-1, -1, -1, 0, 0, 1, 1, 1};

using P = pair<int, int>;

int H, W;
bool is_inbound(int h, int w) {
  return 0 <= h && h < H && 0 <= w && w < W;
}

void dfs(const vs& grid, vvb& visited, ci start_h, ci start_w) {
  visited[start_h][start_w] = true;

  stack<P> st;
  st.push({start_h, start_w});

  while (!st.empty()) {
    auto [h, w] = st.top();
    st.pop();

    rep(k, 8) {
      int nh = h + dh[k];
      int nw = w + dw[k];

      if (!is_inbound(nh, nw)) continue;
      if (grid[nh][nw] != '#') continue;
      if (visited[nh][nw]) continue;

      visited[nh][nw] = true;
      st.push({nh, nw});
    }
  }
}

int main() {
  cin >> H >> W;

  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  vvb visited(H, vector<bool>(W, 0));

  int id{};
  rep(h, H) rep(w, W) {
    if (visited[h][w]) continue;
    if (grid[h][w] != '#') continue;

    dfs(grid, visited, h, w);
    id++;
  }
  out(id);
}
