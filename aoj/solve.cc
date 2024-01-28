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

  int n, m, d;
  cin >> n >> m >> d;

  vector<string> vs(n);
  rep(i, n) cin >> vs[i];

  int cnt{};

  // horizontal
  rep(i, n) {
    rep(j, m - d + 1) {
      bool is_ok{true};
      rep(k, d) {
        if (vs[i][j + k] != '.') {
          is_ok = false;
        }
      }
      if (is_ok) cnt++;
    }
  }

  // vertical
  rep(i, n - d + 1) {
    rep(j, m) {
      bool is_ok{true};
      rep(k, d) {
        if (vs[i + k][j] != '.') {
          is_ok = false;
        }
      }
      if (is_ok) cnt++;
    }
  }

  output(cnt);
}
