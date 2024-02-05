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

char rot(char ch, int h, int w) {
  if (ch == 'B') {
    if ((h + w) % 2 == 0)
      return 'B';
    else
      return 'W';
  } else {
    if ((h + w) % 2 == 0)
      return 'W';
    else
      return 'B';
  }
}

int main() {
  FastIO;

  int W, H;
  char c;
  cin >> W >> H >> c;

  rep(h, H) {
    rep(w, W) {
      cout << rot(c, h, w);
    }
    cout << '\n';
  }
}
