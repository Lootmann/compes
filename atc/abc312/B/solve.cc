#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do {cout << msg << endl;exit(0);} while (0)
#define el '\n'

#define all(k)  k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  rep(i, n) cin >> grid[i];

  vector<pair<int, int>> pos;

  rep(h, n - 8) rep(w, m - 8) {
    bool can_paint{true};

    // black
    rep(y, 3) rep(x, 3) {
      if (grid[h + y][w + x] != '#') {
        can_paint = false;
      }

      if (grid[h + y + 6][w + x + 6] != '#') {
        can_paint = false;
      }
    }

    // white
    rep(k, 4) {
      if (grid[h + 3][w + k] != '.') {
        can_paint = false;
      }
      if (grid[h + k][w + 3] != '.') {
        can_paint = false;
      }
      if (grid[h + 5][w + k + 5] != '.') {
        can_paint = false;
      }
      if (grid[h + k + 5][w + 5] != '.') {
        can_paint = false;
      }
    }

    if (can_paint) {
      pos.push_back({h + 1, w + 1});
    }
  }

  if (pos.size() == 0) {
    cout << el;
  } else {
    for (auto [y, x] : pos) {
      cout << y << ' ' << x << el;
    }
  }
}
