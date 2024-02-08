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

void solve() {
  vector<string> grid(8);
  rep(i, 8) cin >> grid[i];

  int red{}, blue{};

  rep(h, 8) {
    int r{};
    rep(w, 8) if (grid[h][w] == 'R') r++;
    chmax(red, r);
  }

  rep(w, 8) {
    int b{};
    rep(h, 8) if (grid[h][w] == 'B') b++;
    chmax(blue, b);
  }

  if (red == 8) {
    out("R");
  } else {
    out("B");
  }
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
