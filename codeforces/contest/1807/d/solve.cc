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
  // length or array, queries
  llint n, q;
  cin >> n >> q;

  vector<llint> ai(n);
  rep(i, n) cin >> ai[i];
  dump(ai);

  vector<llint> acc(n + 1, 0);
  rep(i, n) acc[i + 1] = acc[i] + ai[i];
  dump(acc);

  rep(_, q) {
    llint l, r, k;
    cin >> l >> r >> k;
    l--, r--;

    llint left = acc[l];
    llint mid_sum = (r - l + 1) * k;
    llint right = acc[n] - acc[r + 1];

    llint all_sum = left + mid_sum + right;
    if (all_sum % 2 == 1) {
      out("YES");
    } else {
      out("NO");
    }
  }
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
