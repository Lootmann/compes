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

  int n, x;
  while (cin >> n >> x) {
    if (n == 0 && x == 0) break;

    int cnt{};
    for (int a = 1; a <= n; ++a) {
      for (int b = a + 1; b <= n; ++b) {
        for (int c = b + 1; c <= n; ++c) {
          if (a + b + c == x) {
            cnt++;
          }
        }
      }
    }
    output(cnt);
  }
}
