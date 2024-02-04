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

  int n;
  cin >> n;
  vector<vector<int>> sheet(101, vector<int>(101, 0));

  rep(_, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int y = c; y < d; ++y) {
      for (int x = a; x < b; ++x) {
        sheet[y][x]++;
      }
    }
  }

  int cnt{};
  rep(i, 101) rep(j, 101) {
    if (sheet[i][j] >= 1) {
      cnt++;
    }
  }
  output(cnt);
}
