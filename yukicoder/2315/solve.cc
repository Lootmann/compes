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

int manhattan(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> xi(n), yi(n);
  rep(i, n) cin >> xi[i] >> yi[i];

  int ans{300 * 300 * 2 + 1};

  for (int x = 1; x <= 300; ++x) {
    for (int y = 1; y <= 300; ++y) {
      int dist{};
      rep(i, n) {
        dist += manhattan(x, y, xi[i], yi[i]);
      }
      chmin(ans, dist);
    }
  }

  out(ans);
}
