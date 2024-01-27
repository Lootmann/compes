#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
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

void bfs(Graph& graph, int from) {
  int N = (int)graph.size();

  vector<bool> visited(N, false);
  visited[from] = true;

  queue<int> que;
  que.push(from);

  vector<int> dist(N, -1);
  dist[from] = 0;

  while (!que.empty()) {
    // start
    int u = que.front();
    que.pop();

    // neighbors
    for (auto nv : graph[u]) {
      if (!visited[nv]) {
        visited[nv] = true;
        dist[nv] = dist[u] + 1;
        que.push(nv);
      }
    }
  }

  rep(i, N) {
    cout << i + 1 << ' ' << dist[i] << '\n';
  }
}

int main() {
  FastIO;
  int N;
  cin >> N;

  // unweighted directed graph
  Graph graph(N);

  rep(_, N) {
    int v, n;
    cin >> v >> n;

    rep(i, n) {
      int nv;
      cin >> nv;
      graph[v - 1].push_back(nv - 1);
    }
  }

  // start from 0 vertex
  bfs(graph, 0);
}
