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
  int n, m;
  cin >> n >> m;

  vector<string> flag(n);
  rep(i, n) cin >> flag[i];

  int ans{50 * 50};

  for (int a = 1; a < n; ++a) {
    for (int b = 1; b < n; ++b) {
      int c = n - a - b;
      if (!(1 <= a && 1 <= b && 1 <= c)) continue;
      if (a + b + c != n) continue;

      // white
      int white{};
      for (int i = 0; i < a; ++i) {
        rep(x, m) if (flag[i][x] != 'W') {
          white++;
        }
      }

      // blue
      int blue{};
      for (int i = a; i < a + b; ++i) {
        rep(x, m) if (flag[i][x] != 'B') {
          blue++;
        }
      }

      // red
      int red{};
      for (int i = a + b; i < n; ++i) {
        rep(x, m) if (flag[i][x] != 'R') {
          red++;
        }
      }

      chmin(ans, white + blue + red);
    }  // for b
  }    // for a

  cout << ans << el;
}
