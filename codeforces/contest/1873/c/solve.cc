#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

using llint = long long int;

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

vector<vector<int>> grid(10, vector<int>(10, 0));

void solve() {
  int score{};

  rep(h, 10) {
    string line;
    cin >> line;

    rep(w, 10) {
      if (line[w] == 'X') {
        score += grid[h][w];
      }
    }
  }
  out(score);
}

int main() {
  FastIO;
  // init
  grid = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
          {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
          {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
          {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
          {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
          {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
          {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
          {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
          {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}

  };
  int t;
  cin >> t;
  while (t--) solve();
}
