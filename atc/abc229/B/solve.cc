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
  string s, t;
  cin >> s >> t;

  int loop = min((int)s.size(), (int)t.size());

  bool is_hard{false};
  rep(i, loop) {
    int ss = s[(int)s.size() - 1 - i] - '0';
    int tt = t[(int)t.size() - 1 - i] - '0';
    if (ss + tt >= 10) is_hard = true;
  }

  if (is_hard)
    output("Hard");
  else
    output("Easy");
}
