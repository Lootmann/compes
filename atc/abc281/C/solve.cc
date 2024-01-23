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
  llint n, t;
  cin >> n >> t;

  // cumulative sum test
  vector<llint> acc(n + 1, 0);
  rep(i, n) {
    llint a;
    cin >> a;
    // 10^5 * 10^9 -> not overflow
    acc[i + 1] = acc[i] + a;
  }
  dump(acc);

  llint rest = t % acc[n];
  dump(rest);

  rep(i, n) {
    if (acc[i] <= rest && rest <= acc[i + 1]) {
      cout << i + 1 << ' ' << rest - acc[i] << endl;
      break;
    }
  }
}
