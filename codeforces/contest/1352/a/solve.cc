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
  string s;
  cin >> s;

  vector<string> ans;
  int n = (int)s.size();
  rep(i, n) {
    string k;
    if (s[i] != '0') {
      k.push_back(s[i]);
      rep(_, n - i - 1) {
        k.push_back('0');
      }
      ans.push_back(k);
    }
  }

  out(ans.size());
  int nn = (int)ans.size();
  rep(i, nn) {
    cout << ans[i] << (i == nn - 1 ? '\n' : ' ');
  }
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
