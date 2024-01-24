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

bool is_good(char a, char b) {
  if (a == 'W') return b == 'L';
  if (a == 'L') return b == 'W';
  return a == 'D' && b == 'D';
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<string> sheet(n);
  rep(i, n) cin >> sheet[i];

  rep(y, n) {
    rep(x, n) {
      if (y == x) continue;
      char a = sheet[y][x];
      char b = sheet[x][y];
      if (!is_good(a, b)) die("incorrect");
    }
  }

  output("correct");
}
