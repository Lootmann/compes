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

using ci = const int;
int Y, X, k;

bool is_inbound(int y, int x) {
  return 0 <= y && y < Y && 0 <= x && x < X;
}

bool search(const vector<string>& grid, ci& y, ci& x) {
  for (int dy = -k + 1; dy < k; ++dy) {
    for (int dx = -k + 1; dx < k; ++dx) {
      // outbound
      if (!is_inbound(y + dy, x + dx)) return false;

      if (abs(dy) + abs(dx) < k) {
        if (grid[y + dy][x + dx] == 'x') return false;
      }
    }
  }

  return true;
}

int main() {
  cin >> Y >> X >> k;

  vector<string> grid(Y);
  rep(i, Y) cin >> grid[i];

  int cnt{};
  rep(y, Y) rep(x, X) {
    if (grid[y][x] == 'x') continue;
    if (search(grid, y, x)) {
      cnt++;
    }
  }
  out(cnt);
}
