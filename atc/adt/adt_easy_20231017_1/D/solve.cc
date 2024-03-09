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

  vector<vector<int>> xi(n, vector<int>(n, 0));
  rep(_, m) {
    int k;
    cin >> k;

    vector<int> ps(k);
    rep(i, k) cin >> ps[i], ps[i]--;

    for (int i = 0; i < k; ++i) {
      for (int j = i + 1; j < k; ++j) {
        xi[ps[i]][ps[j]] = 1;
        xi[ps[j]][ps[i]] = 1;
      }
    }
  }

  rep(i, n) dump(xi[i]);

  rep(i, n) rep(j, n) {
    if (i != j) {
      if (xi[i][j] == 0 || xi[j][i] == 0) die("No");
    }
  }
  cout << "Yes" << el;
}
