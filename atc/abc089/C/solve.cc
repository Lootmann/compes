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

  // m a r c h
  vector<llint> names(5, 0);
  rep(_, n) {
    string s;
    cin >> s;
    if (s[0] == 'M') names[0]++;
    if (s[0] == 'A') names[1]++;
    if (s[0] == 'R') names[2]++;
    if (s[0] == 'C') names[3]++;
    if (s[0] == 'H') names[4]++;
  }

  dump(names);

  llint cnt{0};
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      for (int k = j + 1; k < 5; ++k) {
        cnt += names[i] * names[j] * names[k];
      }
    }
  }
  output(cnt);
}
