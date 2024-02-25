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

namespace me {

bool binary_search(const vector<int>& ai, int k) {
  int l = 0, r = (int)ai.size() - 1;

  while (l <= r) {
    int m = (l + r) / 2;

    if (ai[m] == k) {
      return true;
    } else if (k < ai[m]) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  return false;
}
}  // namespace me

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];
  sort(all(ai));

  if (me::binary_search(ai, x)) {
    cout << "Yes" << el;
  } else {
    cout << "No" << el;
  }
}
