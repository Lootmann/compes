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

int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
  int n;
  cin >> n;

  vector<string> grid(n * 2);
  rep(i, n) {
    cin >> grid[i];
    grid[i] += grid[i];
  }
  rep(i, n) grid[i + n] = grid[i];

  llint maxv{};
  rep(y, 2 * n) rep(x, 2 * n) rep(d, 8) {
    int ny = y, nx = x;
    llint now{};

    rep(k, n) {
      ny += dy[d];
      nx += dx[d];
      if (!(0 <= ny && ny < 2 * n && 0 <= nx && nx < 2 * n)) {
        now = 0;
        break;
      }
      now *= 10;
      now += grid[ny][nx] - '0';
    }
    chmax(maxv, now);
  }

  out(maxv);
}
