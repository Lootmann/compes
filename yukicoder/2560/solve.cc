#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define EACH(x, a) for (auto& x : a)
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
  llint n, x;
  cin >> n >> x;

  llint sum = n * (n + 1) / 2;
  if (sum > x) {
    output(-1);
  } else {
    llint diff = x - sum;
    for (int i = 1; i < n; ++i) {
      cout << i << ' ';
    }
    cout << n + diff << '\n';
  }
}

int main() {
  FastIO;
  int t;
  cin >> t;
  rep(_, t) solve();
}
