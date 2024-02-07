#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
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
  int b0, c0, b1, c1;
  cin >> b0 >> c0 >> b1 >> c1;

  // - to +
  int b = ((c0 % b0) + b0) % b0;
  int c = ((c1 % b1) + b1) % b1;

  for (int x = 0; x <= b0 * b1; ++x) {
    if ((x % b0 == b) && (x % b1 == c)) {
      die(x);
    }
  }

  out("NaN");
}
