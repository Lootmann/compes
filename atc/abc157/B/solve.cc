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
  vector<vector<int>> ai(3, vector<int>(3));
  rep(h, 3) rep(w, 3) cin >> ai[h][w];

  int n;
  cin >> n;

  rep(i, n) {
    int b;
    cin >> b;

    rep(h, 3) rep(w, 3) {
      if (ai[h][w] == b) {
        ai[h][w] = -1;
      }
    }
  }

  // hor
  rep(i, 3) {
    int a = ai[i][0];
    int b = ai[i][1];
    int c = ai[i][2];
    if (a == -1 && b == -1 && c == -1) die("Yes");
  }

  rep(i, 3) {
    int a = ai[0][i];
    int b = ai[1][i];
    int c = ai[2][i];
    if (a == -1 && b == -1 && c == -1) die("Yes");
  }

  {
    int a = ai[0][0];
    int b = ai[1][1];
    int c = ai[2][2];
    if (a == -1 && b == -1 && c == -1) die("Yes");
  }

  {
    int a = ai[0][2];
    int b = ai[1][1];
    int c = ai[2][0];
    if (a == -1 && b == -1 && c == -1) die("Yes");
  }

  out("No");
}
