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

void bfs(Graph& graph, const int n, int id) {
  vector<int> dist(n, -1);
  dist[id] = 0;

  queue<int> que;
  que.push(id);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto nv : graph[v]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  }

  int cnt{};
  rep(i, n) {
    if (dist[i] == 2) cnt++;
  }
  output(cnt);
}

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  rep(_, m) {
    int from, to;
    cin >> from >> to;
    from--, to--;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  rep(id, n) bfs(graph, n, id);
}
