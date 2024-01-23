#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;

  llint n, k;
  cin >> n >> k;

  vector<llint> ai(n);
  rep(i, n) cin >> ai[i];

  map<llint, llint> mp;
  rep(i, n) {
    mp[ai[i]] = k / n;
  }

  llint rest = k % n;
  for (auto& key : mp) {
    if (rest == 0) break;
    rest--;
    key.second++;
  }

  dump(ai);

  // output
  rep(i, n) {
    cout << mp[ai[i]] << '\n';
  }
}
