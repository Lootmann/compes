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
  vector<string> vs(n);

  map<string, bool> mp;
  for (int i = 0; i < n; i++) {
    cin >> vs[i];
    mp[vs[i]] = true;
  }

  rep(i, n) {
    bool ok = false;

    for (int j = 1; j < (int)vs[i].size(); j++) {
      string ss = vs[i].substr(0, j);
      string tt = vs[i].substr(j, vs[i].length() - j);

      if (mp[ss] && mp[tt]) {
        ok = true;
      }
    }
    cout << ok;
  }
  cout << '\n';
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
