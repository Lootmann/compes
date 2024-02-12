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

const int dh[]{0, 1, 1, -1};
const int dw[]{1, 0, 1, 1};

int main() {
  int n;
  cin >> n;

  vector<string> grid(n);
  rep(i, n) cin >> grid[i];

  int H = n, W = (int)grid[0].size();

  rep(h, H) rep(w, W) rep(d, 4) {
    int nh = h;
    int nw = w;
    int cnt{};

    rep(k, 6) {
      if (!(0 <= nh && nh < H && 0 <= nw && nw < W)) {
        cnt = -100;
        break;
      }
      if (grid[nh][nw] == '#') cnt++;

      nh += dh[d];
      nw += dw[d];
    }

    if (cnt >= 4) die("Yes");
  }

  // output
  out("No");
}
