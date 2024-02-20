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
#define el '\n'

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

map<llint, llint> mp;

llint f(llint n) {
  if (n <= 2) return mp[n];
  if (mp.contains(n)) return mp[n];

  if (n % 2 == 0) {
    return mp[n] = n + f(n / 2) + f(n / 2);
  } else {
    return mp[n] = n + f(n / 2) + f(n / 2 + 1);
  }
}

int main() {
  llint n;
  cin >> n;

  mp[0] = 0;
  mp[1] = 0;
  mp[2] = 2;

  cout << f(n) << el;
}
