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
#define out(msg) cout << msg << '\n'
#define die(msg) do{ cout << msg << endl,exit(0); }while(0)
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

namespace me {
int lower_bound(const vector<int>& ai, int k) {
  int n = size(ai);
  int left{-1}, right{n};

  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (ai[mid] <= k)
      left = mid;
    else
      right = mid;
  }

  return left + 1;
}

int calc(int k, int xi, int ai) {
  return max(k - abs(xi - ai), 0);
}
}  // namespace me

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> ai(n), xi(m);
  rep(i, n) cin >> ai[i];
  rep(i, m) cin >> xi[i];

  sort(all(ai));

  rep(i, m) {
    int x = xi[i];

    // lower bound
    int idx = me::lower_bound(ai, x);
    int intensity{0};

    if (0 < idx) {
      chmax(intensity, me::calc(k, x, ai[idx - 1]));
    }
    if (idx < n) {
      chmax(intensity, me::calc(k, x, ai[idx]));
    }

    cout << intensity << el;
  }
}
