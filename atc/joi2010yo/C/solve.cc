#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
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
  int n;
  cin >> n;

  Graph graph(n);
  int m;
  cin >> m;
  rep(_, m) {
    int from, to;
    cin >> from >> to;
    from--, to--;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  int sv = 0;
  vector<int> dist(n, -1);
  vector<bool> visited(n, false);
  visited[sv] = true;
  dist[sv] = 0;

  queue<int> que;
  que.push(sv);

  while (!que.empty()) {
    int v = que.front();
    que.pop();

    for (auto nv : graph[v]) {
      if (visited[nv]) continue;
      dist[nv] = dist[v] + 1;
      visited[nv] = true;
      que.push(nv);
    }
  }

  dump(dist);
  dump(visited);
  int cnt{};
  rep(i, n) {
    if (dist[i] == 1 || dist[i] == 2) cnt++;
  }
  cout << cnt << el;
}
