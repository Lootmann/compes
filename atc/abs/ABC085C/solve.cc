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
#define INTi 1 << 30
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

  int n, y;
  cin >> n >> y;

  // y == 10000a + 5000b + 1000c;
  for (int a = 0; a <= n; ++a) {
    for (int b = 0; b <= n; ++b) {
      int rest = y - 10000 * a - 5000 * b;
      if (rest < 0) continue;
      int c = rest / 1000;
      if (10000 * a + 5000 * b + 1000 * c == y && a + b + c == n) {
        cout << a << ' ' << b << ' ' << c << endl;
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}
