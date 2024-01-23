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
  int x, n;
  cin >> x >> n;

  set<int> pi;
  rep(i, n) {
    int p;
    cin >> p;
    pi.insert(p);
  }

  int diff{101 * 2}, ans{101 * 2};

  // upper
  rep(i, 202) {
    if (!pi.contains(i)) {
      int d = abs(i - x);
      if (diff > d) {
        diff = d;
        ans = i;
      }
    }
    dump(diff, ans);
  }

  dump(ans);
  output(ans);
}
