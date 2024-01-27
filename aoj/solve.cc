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

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<vector<int>> graph(n, vector<int>(n, 0));

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
      graph[u][v] = 1;
    }
  }

  rep(h, n) {
    rep(w, n) {
      cout << graph[h][w] << (w == n - 1 ? '\n' : ' ');
    }
  }
}
