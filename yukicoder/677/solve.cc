#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

void solve() {
  int n;
  cin >> n;

  llint a{1};
  rep(_, n) a *= 10;

  map<llint, int> mp;
  for (llint i = 1; i <= n; ++i) {
    if (a % 2 == 0) mp[2]++;
    if (a % 5 == 0) mp[5]++;
  }

  set<llint> st;

  rep(i, mp[2] + 1) {
    llint res{1};
    rep(_, i) res *= 2;

    rep(j, mp[5] + 1) {
      llint ans{res};
      rep(__, j) ans *= 5;

      st.insert(ans);
    }
  }

  for (auto key : st) {
    output(key);
  }
}

int main() {
  FastIO;
  solve();
}
