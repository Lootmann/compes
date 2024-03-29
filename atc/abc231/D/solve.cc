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
#define el '\n'

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

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  vector<int> deg(n, 0);

  rep(_, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    graph[a].push_back(b);
    graph[b].push_back(a);

    deg[a]++;
    deg[b]++;
  }

  // all deg should have under 2
  rep(i, n) {
    if (deg[i] > 2) die("No");
  }

  // path cycle
  vector<bool> visited(n, false);

  auto dfs = [&](auto f, int prev, int v) -> void {
    visited[v] = true;

    for (auto nv : graph[v]) {
      // same from and to vertex
      // this requires only undirected graph?
      if (prev != nv) {
        // already visited
        if (visited[nv]) {
          die("No");
        }
        f(f, v, nv);
      }
    }
  };

  rep(i, n) {
    if (!visited[i]) dfs(dfs, -1, i);
  }

  out("Yes");
}
