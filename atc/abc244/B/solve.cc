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
  string s;
  cin >> n >> s;

  int y{0}, x{0};
  int d{1};  // direction

  rep(i, n) {
    if (s[i] == 'S') {
      if (d == 0) {
        y++;
      } else if (d == 1) {
        x++;
      } else if (d == 2) {
        y--;
      } else if (d == 3) {
        x--;
      }
    } else {
      d = (d + 1) % 4;
    }
  }

  cout << x << ' ' << y << '\n';
}
