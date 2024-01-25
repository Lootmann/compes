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

  llint n;
  cin >> n;

  // x^2 + y^2 = n*2
  // y^2 = n*2 - x^2
  int cnt{};
  for (llint x = 1; x <= 200000; ++x) {
    llint y = n * n - x * x;
    if (y > 0) {
      llint yy = sqrt(y);

      if (x * x + yy * yy == n * n) {
        cnt++;
      }
    }
  }
  output(cnt);
}
