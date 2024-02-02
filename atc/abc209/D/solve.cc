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
template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;
using Graph = vector<vector<int>>;

void bfs(const Graph& graph, vector<int>& dist) {
  int vertex{0};
  dist[vertex] = 0;

  queue<int> que;
  que.push(vertex);

  while (!que.empty()) {
    vertex = que.front();
    que.pop();
    dump(vertex);

    for (auto nv : graph[vertex]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[vertex] + 1;
        que.push(nv);
      }
    }
  }
}

int main() {
  FastIO;

  int N, Q;
  cin >> N >> Q;

  Graph graph(N);
  rep(_, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<int> dist(N, -1);

  bfs(graph, dist);

  rep(_, Q) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    if (dist[c] % 2 == dist[d] % 2) {
      output("Town");
    } else {
      output("Road");
    }
  }
}
