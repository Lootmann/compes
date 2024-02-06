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

void solve() {
  int l, r, a, b;
  cin >> l >> r >> a >> b;

  int mx{-1000 * 1000 - 1001};
  for (int x = l; x <= r; ++x) {
    chmax(mx, a * x + b);
  }
  output(mx);
}

int main() {
  FastIO;
  int t;
  cin >> t;

  rep(_, t) solve();
}
