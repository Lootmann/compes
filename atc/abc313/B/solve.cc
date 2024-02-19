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
  rep(_, m) {
    int from, to;
    cin >> from >> to;
    from--, to--;
    graph[from].push_back(to);
  }

  // 閉路がない かつ 全ノードを探索済み
  auto dfs = [&](int sv) -> bool {
    vector<bool> visited(n, false);
    visited[sv] = true;

    stack<int> st;
    st.push(sv);

    while (!st.empty()) {
      int v = st.top();
      st.pop();

      for (auto nv : graph[v]) {
        if (visited[nv]) continue;
        visited[nv] = true;
        st.push(nv);
      }
    }

    // check all node were visited
    rep(i, n) {
      if (!visited[i]) return false;
    }

    return true;
  };

  int ans{-1};
  rep(i, n) {
    if (dfs(i)) {
      ans = i + 1;
      dump(i);
    }
  }
  cout << ans << el;
}
