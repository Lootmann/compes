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
  int W, H, n;
  cin >> W >> H >> n;

  vector<vector<bool>> grid(H, vector<bool>(W, false));
  rep(_, n) {
    int xi, yi, a;
    cin >> xi >> yi >> a;

    if (a == 1) {
      for (int y = 0; y < H; ++y) {
        for (int x = 0; x < xi; ++x) {
          grid[y][x] = true;
        }
      }
    } else if (a == 2) {
      for (int y = 0; y < H; ++y) {
        for (int x = xi; x < W; ++x) {
          grid[y][x] = true;
        }
      }
    } else if (a == 3) {
      for (int y = 0; y < yi; ++y) {
        for (int x = 0; x < W; ++x) {
          grid[y][x] = true;
        }
      }
    } else {
      for (int y = yi; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
          grid[y][x] = true;
        }
      }
    }
  }

  int cnt{};
  rep(h, H) rep(w, W) {
    if (!grid[h][w]) cnt++;
  }
  out(cnt);
}
