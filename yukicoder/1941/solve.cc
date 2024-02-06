#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << msg << '\n'
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

  int dy[]{0, -1, 1, 0};
  int dx[]{-1, 0, 0, 1};

  vector<string> cells(3);
  rep(i, 3) cin >> cells[i];

  rep(y, 3) {
    rep(x, 3) {
      char cell = cells[y][x];

      // UDLR
      rep(i, 4) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < 3 && 0 <= nx && nx < 3) {
          if (cell == cells[ny][nx]) {
            die("No");
          }
        }
      }
    }
  }

  output("Yes");
}
