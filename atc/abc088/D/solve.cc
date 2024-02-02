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
using Graph = vector<string>;

int dy[]{-1, 0, 0, 1};
int dx[]{0, 1, -1, 0};
int H, W;
bool can_goal{false};
vector<vector<int>> visited;

struct Pos {
  int y;
  int x;
  Pos(int _y, int _x) : y(_y), x(_x) {}
};

bool is_inbound(int y, int x) {
  return 0 <= y && y < H && 0 <= x && x < W;
}

void bfs(const Graph& graph, int gy, int gx) {
  int y = 0, x = 0;
  visited[y][x] = 1;
  queue<Pos> que;
  que.push(Pos(y, x));

  while (!que.empty()) {
    Pos p = que.front();
    que.pop();

    rep(k, 4) {
      int ny = p.y + dy[k];
      int nx = p.x + dx[k];

      if (ny == gy && nx == gx) can_goal = true;

      if (!is_inbound(ny, nx)) continue;
      if (visited[ny][nx] != 0) continue;
      if (graph[ny][nx] == '#') continue;

      visited[ny][nx] = visited[p.y][p.x] + 1;
      que.push(Pos(ny, nx));
    }
  }  // end bfs
}

int main() {
  FastIO;

  cin >> H >> W;

  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  visited.resize(H, vector<int>(W, 0));
  int gy = H - 1, gx = W - 1;
  bfs(grid, gy, gx);

  if (!can_goal) die(-1);

  int dist = visited[H - 1][W - 1];
  int dot{};
  rep(h, H) rep(w, W) {
    if (grid[h][w] == '.') dot++;
  }

  output(dot - dist);
}
