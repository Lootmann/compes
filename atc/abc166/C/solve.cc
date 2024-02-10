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

using Graph = vector<set<int>>;
using vi = vector<int>;
using ci = const int;

bool dfs(const Graph& graph, const vi& hi, ci N, ci vertex) {
  bool is_highest{true};

  stack<int> st;
  st.push(vertex);

  vector<bool> visited(N, false);
  visited[vertex] = false;

  int height = hi[vertex];

  while (!st.empty()) {
    int v = st.top();
    st.pop();

    for (auto nv : graph[v]) {
      if (height <= hi[nv]) {
        is_highest = false;
      }

      if (!visited[nv]) continue;
      visited[nv] = true;
      st.push(nv);
    }
  }

  return is_highest;
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> hi(N);
  rep(i, N) cin >> hi[i];

  Graph graph(N);
  rep(_, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    graph[a].insert(b);
    graph[b].insert(a);
  }

  int cnt{};
  rep(i, N) {
    if (dfs(graph, hi, N, i)) cnt++;
  }
  out(cnt);
}
