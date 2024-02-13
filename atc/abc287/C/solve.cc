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
using Graph = vector<vector<int>>;

// ordinary dfs
// BFSでも勿論結果は同じになる
void dfs(const Graph& graph, vector<int>& dist, int vertex) {
  dist[vertex] = 0;

  stack<int> st;
  st.push(vertex);

  while (!st.empty()) {
    int v = st.top();
    st.pop();

    for (auto nv : graph[v]) {
      if (dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      st.push(nv);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  // 各頂点と辺の関係性
  //
  // o - o - o - o - o
  // => 頂点 == 辺 - 1
  if (m != n - 1) die("No");

  Graph graph(n);

  rep(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // ある頂点からは多くとも1本または2本しか出ていない
  rep(i, n) {
    auto size = graph[i].size();
    if (!(size == 1 || size == 2)) die("No");
  }

  vector<int> dist(n, -1);

  // 連結成分を考えるとある頂点から全頂点に到達できる
  // 適当な頂点から出発してよい
  dfs(graph, dist, 0);

  sort(all(dist));

  // 連結してない成分がある?
  rep(i, n) if (dist[i] == -1) die("No");
  out("Yes");
}
