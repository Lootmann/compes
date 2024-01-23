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

  // 4%num, 2%num, odd
  int mod4{}, mod2{}, odd{};
  rep(i, n) {
    if (ai[i] % 4 == 0) {
      mod4++;
    } else if (ai[i] % 2 == 0) {
      mod2++;
    } else {
      odd++;
    }
  }

  if (mod4 == 0) {
    if (mod2 >= 2 && odd == 0) die("Yes");
    die("No");
  }

  if (mod4 >= odd) die("Yes");
  if (mod4 + 1 == odd) {
    if (mod2 == 0) die("Yes");
    die("No");
  }

  die("No");
}
