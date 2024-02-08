#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

using llint = long long int;

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

void solve() {
  int n;
  string s;
  cin >> n >> s;

  bool can_get_candy{false};
  int y{0}, x{0};
  for (auto ch : s) {
    if (ch == 'U')
      y++;
    else if (ch == 'D')
      y--;
    else if (ch == 'R')
      x++;
    else if (ch == 'L')
      x--;

    if (y == 1 && x == 1) {
      can_get_candy = true;
    }
  }

  if (can_get_candy)
    out("YES");
  else
    out("NO");
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
