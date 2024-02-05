#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define INFi 1 << 30
#define INFll 1LL << 60

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

  int ans{1000000};
  int n = (int)s.size();

  rep(i, n) {
    if (s[i] == 'c') {
      int idx = i + 1, w{};
      while (idx < n) {
        if (s[idx++] == 'w') {
          w++;
        }
        if (w == 2) break;
      }

      if (w == 2) {
        chmin(ans, idx - i);
      }
    }
  }

  if (ans == 1000000)
    output(-1);
  else
    output(ans);
}
