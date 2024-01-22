#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
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

  reverse(s.begin(), s.end());
  dump(s);

  // WBWBWB
  int len = (int)s.size();
  llint ans{}, cnt{};

  for (int i = 0; i < len; ++i) {
    if (s[i] == 'B') {
      ans += i - cnt;
      cnt++;
    }
  }

  output(ans);
}
