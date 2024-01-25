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
  int n;
  cin >> n;

  vector<int> ti(n + 1, 0), xi(n + 1, 0), yi(n + 1, 0);

  rep(i, n) cin >> ti[i + 1] >> xi[i + 1] >> yi[i + 1];
  dump(ti);
  dump(xi);
  dump(yi);

  rep(i, n) {
    int t = ti[i + 1] - ti[i];
    int x = abs(xi[i + 1] - xi[i]);
    int y = abs(yi[i + 1] - yi[i]);
    int dist = x + y;
    if (dist > t) die("No");
    if (dist % 2 != t % 2) die("No");
  }

  output("Yes");
}
