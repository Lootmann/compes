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

  int n;
  cin >> n;

  map<llint, llint> mp;
  rep(_, n) {
    int a;
    cin >> a;
    mp[a]++;
  }

  vector<llint> sides;
  for (auto key : mp) {
    rep(_, key.second / 2) {
      sides.push_back(key.first);
    }
  }

  sort(sides.rbegin(), sides.rend());

  if ((int)sides.size() >= 2)
    output(sides[0] * sides[1]);
  else
    output(0);
}
