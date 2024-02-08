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

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  int valley_idx{}, minv{INFi};
  rep(i, n) {
    if (chmin(minv, ai[i])) {
      valley_idx = i;
    }
  }

  bool is_valley{true};

  // ai[i] <= ai[i + 1]
  for (int i = valley_idx; i < n - 1; ++i) {
    if (ai[i] > ai[i + 1]) {
      is_valley = false;
    }
  }

  // ai[i - 1] >= ai[i]
  for (int i = valley_idx; i > 0; --i) {
    if (ai[i - 1] < ai[i]) {
      is_valley = false;
    }
  }

  if (is_valley)
    out("YES");
  else
    out("NO");
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
