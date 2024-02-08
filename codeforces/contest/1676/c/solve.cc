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
  int n, m;
  cin >> n >> m;

  vector<string> vs(n);
  rep(i, n) cin >> vs[i];

  int min_cost{INFi};
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int cost{};
      rep(k, m) {
        int c1 = vs[i][k] - 'a';
        int c2 = vs[j][k] - 'a';
        cost += abs(c1 - c2);
      }
      chmin(min_cost, cost);
    }
  }
  out(min_cost);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
