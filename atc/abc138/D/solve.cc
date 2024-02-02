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

Graph graph;
vector<int> points;

void dfs(int vertex, int pa = -1) {
  for (auto nv : graph[vertex]) {
    if (nv != pa) {
      points[nv] += points[vertex];
      dfs(nv, vertex);
    }
  }
}

int main() {
  FastIO;
  int N, Q;
  cin >> N >> Q;

  graph.resize(N);
  rep(_, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  points.resize(200000);
  rep(_, Q) {
    int p, x;
    cin >> p >> x;
    points[p - 1] += x;
  }

  dfs(0);

  rep(i, N) {
    cout << points[i] << (i == N - 1 ? '\n' : ' ');
  }
}
