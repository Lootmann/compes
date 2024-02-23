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
  vector<int> hi(3), wi(3);
  rep(i, 3) cin >> hi[i];
  rep(i, 3) cin >> wi[i];

  /*
   * a b c
   * d e f
   * g h i
   * */
  int cnt{};

  for (int a = 1; a <= 30; ++a) {
    for (int b = 1; b <= 30; ++b) {
      for (int d = 1; d <= 30; ++d) {
        for (int e = 1; e <= 30; ++e) {
          int c = hi[0] - a - b;
          int f = hi[1] - d - e;
          int g = wi[0] - a - d;
          int h = wi[1] - b - e;
          int i = wi[2] - c - f;

          if (min({c, f, g, h, i}) > 0 and g + h + i == hi[2]) {
            cnt++;
          }
        }
      }
    }
  }

  cout << cnt << el;
}
