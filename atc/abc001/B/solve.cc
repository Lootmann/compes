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
  int m;
  cin >> m;

  string vv{};
  if (m < 100) {
    vv = "00";
  } else if (m <= 999) {
    vv = "0" + to_string(m / 100);
  } else if (m <= 5000) {
    vv = to_string(m / 100);
  } else if (m <= 30000) {
    int t = m / 1000 + 50;
    vv = to_string(t);
  } else if (m <= 70000) {
    int t = (m / 1000 - 30) / 5 + 80;
    vv = to_string(t);
  } else {
    vv = to_string(89);
  }

  out(vv);
}
