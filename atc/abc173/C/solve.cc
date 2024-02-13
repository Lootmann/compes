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

using vs = vector<string>;
using cvi = const vector<int>;

int count(vector<string> grid, cvi& hi, cvi& wi, int H, int W) {
  for (auto h : hi) {
    rep(w, W) grid[h][w] = '.';
  }

  for (auto w : wi) {
    rep(h, H) grid[h][w] = '.';
  }

  int cnt{};
  rep(h, H) rep(w, W) {
    if (grid[h][w] == '#') {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  int H, W, K;
  cin >> H >> W >> K;

  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  int ans{};

  for (int bit = 0; bit < (1 << H); ++bit) {
    vector<int> hi;
    for (int i = 0; i < H; ++i) {
      if (bit & (1 << i)) {
        hi.push_back(i);
      }
    }

    for (int bit1 = 0; bit1 < (1 << W); ++bit1) {
      vector<int> wi;
      for (int j = 0; j < W; ++j) {
        if (bit1 & (1 << j)) {
          wi.push_back(j);
        }
      }

      int cnt = count(grid, hi, wi, H, W);
      if (cnt == K) {
        ans++;
      }
    }
  }

  out(ans);
}
