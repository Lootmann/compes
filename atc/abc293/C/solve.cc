#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
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
  int H, W;
  cin >> H >> W;

  vector<vector<int>> grid(H, vector<int>(W, 0));
  rep(h, H) rep(w, W) cin >> grid[h][w];

  auto rec = [&](auto f, int h, int w, set<int> trace) -> int {
    if (!(0 <= h && h < H && 0 <= w && w < W)) return 0;
    if (trace.find(grid[h][w]) != trace.end()) return 0;
    if (h == H - 1 && w == W - 1) return 1;

    int cnt{};
    trace.insert(grid[h][w]);
    cnt += f(f, h + 1, w, trace);
    cnt += f(f, h, w + 1, trace);
    return cnt;
  };

  set<int> st;
  int ans = rec(rec, 0, 0, st);
  cout << ans << el;
}
