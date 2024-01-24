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
  llint n, L, a;
  cin >> n >> L >> a;

  if (n == 0) die(L / a);

  vector<llint> ti(n), li(n);
  for (llint i = 0; i < n; ++i) {
    cin >> ti[i] >> li[i];
  }

  llint total{};

  // beginning of the day
  total += ti[0] / a;

  // interval
  for (llint i = 1; i < n; ++i) {
    llint interval = ti[i] - (ti[i - 1] + li[i - 1]);
    total += interval / a;
  }

  // end of the day
  total += (L - (ti[n - 1] + li[n - 1])) / a;

  output(total);
}
