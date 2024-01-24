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

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  int ans{1};
  bool is_inc{false}, is_dec{false};

  int cur = ai[0];

  for (int i = 1; i < n; ++i) {
    if (cur < ai[i]) {
      is_inc = true;
    } else if (cur > ai[i]) {
      is_dec = true;
    }

    if (is_inc && is_dec) {
      is_inc = is_dec = false;
      ans++;
    }
    cur = ai[i];
  }
  output(ans);
}
