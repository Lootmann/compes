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
using Graph = vector<vector<int>>;

int dy[]{0, -1, 1, 0};
int dx[]{-1, 0, 0, 1};
int max_depth{0};
int N, M;

bool is_inbound(int y, int x) {
  return 0 <= y && y < N && 0 <= x && x < M;
}

void dfs(Graph& graph, const int y, const int x, int depth) {
  graph[y][x] = 0;

  rep(k, 4) {
    int ny = y + dy[k];
    int nx = x + dx[k];

    if (!is_inbound(ny, nx)) continue;
    if (graph[ny][nx] != 1) continue;
    dfs(graph, ny, nx, depth + 1);
  }

  graph[y][x] = 1;
  chmax(max_depth, depth);
}

int main() {
  FastIO;
  cin >> N >> M;

  Graph graph(N, vector<int>(M, 0));
  rep(y, N) rep(x, M) cin >> graph[y][x];

  rep(y, N) rep(x, M) {
    if (graph[y][x] == 1) {
      dfs(graph, y, x, 1);
    }
  }

  output(max_depth);
}
