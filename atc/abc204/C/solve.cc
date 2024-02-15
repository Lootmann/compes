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

int dfs(const Graph& graph, const int N, int vertex) {
  stack<int> st{};
  st.push(vertex);

  int id{1};  // start vertex count
  vector<bool> dist(N, false);
  dist[vertex] = id;

  while (!st.empty()) {
    int v = st.top();
    st.pop();

    for (auto nv : graph[v]) {
      if (dist[nv] != 0) continue;
      dist[nv] = true;
      st.push(nv);
      id++;
    }
  }

  return id;
}

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n);

  rep(_, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
  }

  rep(i, n) dump(graph[i]);

  int sum{};
  rep(i, n) sum += dfs(graph, n, i);
  cout << sum << '\n';
}
