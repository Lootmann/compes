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

int dy[]{-1, 0, 0, 1};
int dx[]{0, -1, 1, 0};

int main() {
  int Y, X;
  cin >> Y >> X;

  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;

  vector<string> grid(Y);
  rep(h, Y) cin >> grid[h];

  vector<vector<int>> dist(Y, vector<int>(X, -1));
  queue<pair<int, int>> que;

  auto bfs = [&](int start_y, int start_x) {
    dist[start_y][start_x] = 0;
    que.push({start_y, start_x});

    while (!que.empty()) {
      auto [y, x] = que.front();
      que.pop();

      rep(k, 4) {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (!(0 <= ny && ny < Y && 0 <= nx && nx < X)) continue;
        if (grid[ny][nx] == '#') continue;
        if (dist[ny][nx] != -1) continue;

        dist[ny][nx] = dist[y][x] + 1;
        que.push({ny, nx});
      }
    }
  };

  bfs(sy - 1, sx - 1);
  out(dist[gy - 1][gx - 1]);
}
