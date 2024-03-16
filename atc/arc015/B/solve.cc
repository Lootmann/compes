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

int main() {
  int n;
  cin >> n;

  vector<int> cnt(6, 0);
  rep(_, n) {
    double high, low;
    cin >> high >> low;

    if (high >= 35.0) cnt[0]++;
    if (35.0 > high && high >= 30.0) cnt[1]++;
    if (30.0 > high && high >= 25.0) cnt[2]++;
    if (low >= 25.0) cnt[3]++;
    if (high >= 0.0 && 0.0 > low) cnt[4]++;
    if (0.0 > high) cnt[5]++;
  }

  rep(i, 6) {
    cout << cnt[i] << (i == 5 ? '\n' : ' ');
  }
}
