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
  string s;
  cin >> s;

  int has{}, amb{}, not_has{};

  for (auto ch : s) {
    if (ch == 'o') {
      has++;
    } else if (ch == 'x') {
      not_has++;
    } else {
      amb++;
    }
  }

  if (has > 4) die(0);
  if (not_has == 10) die(0);

  // ^ x ^ x ^ x ^
  // ^ x ^ x ^
  int ans{};

  if (has == 4) {
    ans = 4 * 3 * 2 * 1;
  } else if (has == 3) {
    ans = 3 * 4 * 3 + 3 * 2 * amb * 4;
  } else if (has == 2) {
    ans = 2 * 4 + 3 * 2 + 2 * 3 * 4 * amb + 6 * 2 * amb * amb;
  } else if (has == 1) {
    ans = 1 + 4 * amb + 6 * pow(amb, 2) + pow(amb, 3) * 4;
  } else {
    ans = pow(amb, 4);
  }
  out(ans);
}
