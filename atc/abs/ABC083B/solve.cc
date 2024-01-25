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

int digit_sum(int n) {
  int total{};
  while (n > 0) {
    total += n % 10;
    n /= 10;
  }
  return total;
}

int main() {
  FastIO;
  int n, a, b;
  cin >> n >> a >> b;

  int sum{};
  for (int i = 0; i <= n; ++i) {
    int ds = digit_sum(i);
    if (a <= ds && ds <= b) {
      sum += i;
    }
  }
  cout << sum << endl;
}
