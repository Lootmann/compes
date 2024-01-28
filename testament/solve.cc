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

void dfs(Graph& graph, vector<int>& visited, int start, int _id) {
  visited[start] = _id;
  stack<int> st;
  st.push(start);

  while (!st.empty()) {
    int u = st.top();
    st.pop();

    for (auto nv : graph[u]) {
      if (visited[nv] == -1) {
        visited[nv] = _id;
        st.push(nv);
      }
    }
  }
}

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  rep(i, m) {
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  // calc
  vector<int> visited(n, -1);

  int _id{0};
  rep(vertex, n) {
    if (visited[vertex] == -1) {
      dfs(graph, visited, vertex, _id++);
    }
  }

  // queyies
  int q;
  cin >> q;
  rep(_, q) {
    int from, to;
    cin >> from >> to;
    if (visited[from] == visited[to]) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
    }
  }
}
