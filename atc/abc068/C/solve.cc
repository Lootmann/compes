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

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  rep(i, m) {
    int from, to;
    cin >> from >> to;
    from--, to--;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  rep(i, n) {
    bool from_zero{false}, to_n{false};
    for (auto nxt : graph[i]) {
      if (nxt == 0) from_zero = true;
      if (nxt == n - 1) to_n = true;
    }

    if (from_zero && to_n) {
      die("POSSIBLE");
    }
  }

  output("IMPOSSIBLE");
}
