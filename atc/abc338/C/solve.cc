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

llint calc(llint q, llint a, llint b) {
  if (a == 0) return q / b;
  if (b == 0) return q / a;

  return 0LL;
}

int main() {
  int n;
  cin >> n;

  vector<llint> qi(n);
  rep(i, n) cin >> qi[i];

  vector<llint> ai(n), bi(n);
  rep(i, n) cin >> ai[i];
  rep(i, n) cin >> bi[i];

  // qi = x * ai + y * bi
  llint maxq{};
  rep(i, n) chmax(maxq, qi[i]);

  llint ans{};

  // x を決め打ちする
  for (llint x = 0; x <= 1'000'000; ++x) {
    llint y = INFll;

    rep(i, n) {
      // bi[i] を計算する
      llint left = qi[i] - ai[i] * x;
      if (left < 0) {
        y = -1;
      } else if (bi[i] > 0) {
        chmin(y, left / bi[i]);
      }
    }

    if (y > 0) {
      chmax(ans, x + y);
    }
  }

  cout << ans << el;
}
