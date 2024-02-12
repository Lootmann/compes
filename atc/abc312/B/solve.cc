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
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  rep(i, n) cin >> grid[i];

  vector<pair<int, int>> pairs;

  rep(y, n - 8) {
    rep(x, m - 8) {
      bool is_tak{true};

      // search
      rep(h, 3) rep(w, 3) {
        if (grid[y + h][x + w] != '#') is_tak = false;
        if (grid[y + h + 6][x + w + 6] != '#') is_tak = false;
      }

      rep(k, 4) {
        if (grid[y + k][x + 3] != '.') is_tak = false;
        if (grid[y + 3][x + k] != '.') is_tak = false;

        if (grid[y + 5 + k][x + 5] != '.') is_tak = false;
        if (grid[y + 5][x + 5 + k] != '.') is_tak = false;
      }

      if (is_tak) {
        pairs.push_back({y + 1, x + 1});
      }
    }
  }

  sort(all(pairs));

  if (pairs.size() == 0) {
    cout << '\n';
  } else {
    for (auto [y, x] : pairs) {
      cout << y << ' ' << x << '\n';
    }
  }
}
