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
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
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

/********************************
 * Definitions
 ********************************/
//(tl,tr) top-y, top-x
//    +---+
// y  |   |
//    +---+ (by, bx)
//         bottom-y, bottom-x
struct Partition {
  int ty, tx, by, bx;

  void print() { cout << ty << ' ' << tx << ' ' << by << ' ' << bx << el; }
};

/********************************
 * main
 ********************************/
int main() {
  int w, d, n;
  cin >> w >> d >> n;
  dump(w, d, n);

  vector<vector<int>> ai(d, vector<int>(w));
  rep(i, d) rep(j, w) cin >> ai[i][j];

  vector<vector<Partition>> rects(d);
  rep(i, d) rep(k, n) {
    rects[i].push_back(Partition{2 * k, 0, 2 * k + 1, w});
  }

  rep(i, d) rep(k, n) {
    rects[i][k].print();
  }
}
