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
#define INFll 1LL << 61
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

void solve() {
  const int n = 5;

  vector<llint> ai(n), pi(n);
  rep(i, n) cin >> ai[i];
  rep(i, n) cin >> pi[i];

  llint sum{}, num{};
  rep(i, n) {
    sum += ai[i] * (i + 1);
    num += ai[i];
  }

  if (sum / num >= 3) {
    cout << 0 << el;
    return;
  }

  llint ans{INFll};
  for (llint i = n - 1; i >= 0; --i) {
    llint ok = powl(10, 18), ng = 0;
    llint k{};

    while (abs(ok - ng) > 1) {
      k = (ok + ng) / 2;

      // (sum + k * (i+1)) / (num + k) >= 3
      if ((sum + k * (i + 1)) >= 3 * (num + k)) {
        ok = k;
      } else {
        ng = k;
      }
    }

    // cerr << "star " << (i + 1) << ' ' << k * pi[i] << el;
    if (numeric_limits<llint>::max() / pi[i] >= k) {
      chmin(ans, pi[i] * k);
    }
    // cerr << "ans " << ans << el;
  }

  cout << ans << el;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
