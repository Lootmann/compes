#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

using llint = long long int;

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

void solve() {
  int n;
  cin >> n;

  vector<llint> ai(n);
  rep(i, n) cin >> ai[i];

  llint ans{};

  rep(x, n) {
    llint sum{1};
    rep(y, n) {
      if (x == y) {
        sum *= (ai[y] + 1);
      } else {
        sum *= ai[y];
      }
    }
    chmax(ans, sum);
  }

  out(ans);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
