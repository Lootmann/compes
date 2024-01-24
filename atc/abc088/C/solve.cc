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

  vector<vector<int>> grid(3, vector<int>(3, 0));
  rep(h, 3) {
    rep(w, 3) {
      int c;
      cin >> c;
      grid[h][w] = c;
    }
  }

  bool is_good{true};
  dump(is_good);

  // vertical
  rep(i, 2) {
    int diff1 = grid[i][0] - grid[i + 1][0];
    int diff2 = grid[i][1] - grid[i + 1][1];
    int diff3 = grid[i][2] - grid[i + 1][2];
    is_good &= (diff1 == diff2 && diff2 == diff3);
    dump(is_good);
  }

  // horizontal
  rep(i, 2) {
    int diff1 = grid[0][i] - grid[0][i + 1];
    int diff2 = grid[1][i] - grid[1][i + 1];
    int diff3 = grid[2][i] - grid[2][i + 1];
    is_good &= (diff1 == diff2 && diff2 == diff3);
    dump(is_good);
  }

  dump(is_good);

  if (is_good)
    output("Yes");
  else
    output("No");
}
