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
  int n;
  cin >> n;

  vector<string> grid(n);
  rep(i, n) cin >> grid[i];

  rep(i, n) dump(grid[i]);

  int total{};

  // count x
  rep(h, n) {
    rep(w, 9) {
      if (grid[h][w] == 'x') {
        total++;
      }
    }
  }

  rep(w, 9) {
    bool is_series{false};

    rep(h, n) {
      if (grid[h][w] == 'o') {
        is_series = true;
      } else {
        if (is_series) {
          total++;
          is_series = false;
        }
      }
    }

    if (grid[n - 1][w] == 'o' && is_series) {
      total++;
    }
  }

  out(total);
}
