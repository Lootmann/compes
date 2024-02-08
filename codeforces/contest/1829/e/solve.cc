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

using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;

int dy[]{-1, 0, 0, 1};
int dx[]{0, -1, 1, 0};
int n, m;

bool is_inbound(int y, int x) {
  return 0 <= y && y < n && 0 <= x && x < m;
}

int dfs(const vvi& grid, vvb& visited, const int& start_y, const int& start_x) {
  visited[start_y][start_x] = true;
  int sum = grid[start_y][start_x];

  stack<pair<int, int>> st;
  st.push(make_pair(start_y, start_x));

  while (!st.empty()) {
    auto [y, x] = st.top();
    st.pop();

    rep(k, 4) {
      int ny = y + dy[k];
      int nx = x + dx[k];

      if (!is_inbound(ny, nx)) continue;
      if (visited[ny][nx]) continue;
      if (grid[ny][nx] == 0) continue;

      sum += grid[ny][nx];
      visited[ny][nx] = true;
      st.push(make_pair(ny, nx));
    }
  }

  return sum;
}

void solve() {
  cin >> n >> m;

  vvi grid(n, vector<int>(m, 0));
  rep(h, n) rep(w, m) cin >> grid[h][w];

  vvb visited(n, vector<bool>(m, false));

  int max_depth{};
  rep(h, n) rep(w, m) {
    if (grid[h][w] != 0) {
      if (!visited[h][w]) {
        chmax(max_depth, dfs(grid, visited, h, w));
      }
    }
  }
  out(max_depth);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
