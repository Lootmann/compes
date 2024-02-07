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

int main() {
  FastIO;
  int n;
  string s;
  cin >> n >> s;

  //  B A B
  // (B B)B
  //  B(B B)
  int cnt{};
  bool dup{false};
  rep(i, n - 1) {
    auto [x, y] = tuple(s[i], s[i + 1]);

    if (x == 'B' && y == 'B') {
      dup = true;
    } else {
      cnt++;
    }
  }
  if (dup) cnt++;

  rep(i, n - 2) {
    auto [x, y, z] = tuple(s[i], s[i + 1], s[i + 2]);

    if (x == 'B' && y == 'A' && z == 'B') {
      cnt--;
    }
  }
  out(cnt);
}
