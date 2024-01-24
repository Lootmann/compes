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

  string s;
  cin >> s;

  int one{}, zero{};
  int ans{};
  for (auto ch : s) {
    if (ch == '1') {
      one++;
      zero = 0;
    } else {
      zero++;
      one = 0;
    }
    dump(ans, one, zero);
    chmax(ans, max(one, zero));
  }

  if (ans >= 7)
    output("YES");
  else
    output("NO");
}
