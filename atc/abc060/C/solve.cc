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

  vector<llint> ti(n);
  rep(i, n) cin >> ti[i];

  llint total{};
  rep(i, n - 1) {
    llint range = abs(ti[i] - ti[i + 1]);

    if (range < t) {
      total += range;
    } else {
      total += t;
    }
    dump(i, range);
  }
  total += t;
  output(total);
}
