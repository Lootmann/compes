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

  int n;
  llint y;
  cin >> n >> y;

  rep(a, n + 1) {
    rep(b, n + 1) {
      if (a + b > n) break;

      llint c = n - a - b;
      if (0 <= c) {
        if (y == 10000LL * a + 5000LL * b + 1000LL * c) {
          cout << a << ' ' << b << ' ' << c << '\n';
          return 0;
        }
      }
    }
  }

  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}
