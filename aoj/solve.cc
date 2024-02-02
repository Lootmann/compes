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
using VVI = vector<vector<int>>;

int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};

bool is_inbound(int h, int w, int H, int W) {
  return 0 <= h && h < H && 0 <= w && w < W;
}

struct Pos {
  int y;
  int x;
  Pos(int _y, int _x) : y(_y), x(_x) {}
};

void bfs(const Graph& graph, VVI& visited, int h, int w, int H, int W, int id) {
  visited[h][w] = id;

  stack<Pos> st;
  st.push(Pos(h, w));

  while (!st.empty()) {
    Pos v = st.top();
    st.pop();

    rep(k, 8) {
      int nh = v.y + dy[k];
      int nw = v.x + dx[k];
      if (is_inbound(nh, nw, H, W)) {
        if (graph[nh][nw] == 1 && visited[nh][nw] != id) {
          visited[nh][nw] = id;
          st.push(Pos(nh, nw));
        }
      }
    }
  }  // end bfs
}

void solve(const int W, const int H) {
  Graph graph(H, vector<int>(W, 0));
  rep(h, H) rep(w, W) cin >> graph[h][w];

  VVI visited(H, vector<int>(W, false));

  int id{1};
  rep(h, H) rep(w, W) {
    if (graph[h][w] == 1 && !visited[h][w]) {
      bfs(graph, visited, h, w, H, W, id++);
    }
  }

  cerr << "* bfs" << '\n';
  rep(i, H) dump(visited[i]);

  // answer
  int ans{};
  rep(h, H) rep(w, W) {
    chmax(ans, visited[h][w]);
  }
  output(ans);
}

int main() {
  FastIO;
  int W, H;

  while (cin >> W >> H) {
    if (W == 0 && H == 0) break;
    solve(W, H);
  }
}
