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
  int n;
  cin >> n;
  vector<int> xi(n);
  rep(i, n) cin >> xi[i];

  int m;
  cin >> m;
  vector<int> ai(m);
  rep(i, m) cin >> ai[i], ai[i]--;

  for (auto a : ai) {
    if (a < n - 1) {
      if (xi[a] + 1 != xi[a + 1]) {
        if (xi[a] + 1 <= 2019) xi[a]++;
      }
    } else {
      if (xi[a] + 1 <= 2019) xi[a]++;
    }
    dump(xi);
  }

  for (auto x : xi) {
    cout << x << el;
  }
}
