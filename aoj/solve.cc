#include <bits/stdc++.h>

#include <cwchar>
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

  int n, q;
  cin >> n >> q;

  vector<stack<int>> vs(n);
  rep(_, q) {
    int op;
    cin >> op;

    if (op == 0) {
      int t, x;
      cin >> t >> x;
      vs[t].push(x);
    } else if (op == 1) {
      int t;
      cin >> t;
      if (!vs[t].empty()) {
        cout << vs[t].top() << '\n';
      }
    } else {
      int t;
      cin >> t;
      if (!vs[t].empty()) vs[t].pop();
    }
  }
}
