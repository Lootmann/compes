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

// cums
vector<int> discover, finish;
vector<bool> visited;

void dfs(Graph& graph, int v, int& ttime) {
  visited[v] = true;
  discover[v] = ++ttime;

  for (auto nv : graph[v]) {
    if (visited[nv]) continue;
    dfs(graph, nv, ttime);
  }

  finish[v] = ++ttime;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  Graph graph(n);

  rep(_, n) {
    int u;
    cin >> u;
    u--;

    int k;
    cin >> k;
    rep(__, k) {
      int v;
      cin >> v;
      v--;
      graph[u].push_back(v);
      // graph[v].push_back(u);
    }
  }

  discover.resize(n, 0);
  finish.resize(n, 0);
  visited.assign(n, false);
  int time{0};

  rep(v, n) {
    if (!visited[v]) {
      dfs(graph, v, time);
    }
  }

  rep(i, n) {
    cout << i + 1 << ' ' << discover[i] << ' ' << finish[i] << '\n';
  }
}
