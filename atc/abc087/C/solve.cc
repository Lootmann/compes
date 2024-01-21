#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define repa(i, a, n) for (int i = a; (int)i < n; ++i)
#define rrep(i, n) for (int i = n; (int)i >= 0; --i)
#define rrepa(i, a, n) for (int i = a; (int)i >= n; --i)
#define EACH(x, a) for (auto& x : a)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)

template <class A> void read(vector<A>& v);
template <class A, size_t S> void read(array<A, S>& a);
template <class T> void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T> void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A> void read(vector<A>& x) {
  EACH(a, x) read(a);
}
template <class A, size_t S> void read(array<A, S>& x) {
  EACH(a, x) read(a);
}
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
  read(n);

  vector<vector<int>> cells(2, vector<int>(n, 0));
  rep(i, 2) rep(j, n) {
    int a;
    read(a);
    cells[i][j] = a;
  }

  // dp
  vector<vector<int>> dp(2, vector<int>(n, 0));

  // cells[0][n] is invariant
  rep(i, n) {
    if (i == 0) {
      dp[0][0] = cells[0][0];
    } else {
      dp[0][i] = cells[0][i] + dp[0][i - 1];
    }
  }

  // * update direction
  // [ ]   [ ]
  //        |
  //        v
  // [ ] ->
  rep(i, n) {
    if (i == 0) {
      chmax(dp[1][0], dp[0][0] + cells[1][0]);
    } else {
      int maxc = max(dp[0][i], dp[1][i - 1]) + cells[1][i];
      chmax(dp[1][i], maxc);
    }
  }
  dump(dp[0]);
  dump(dp[1]);

  output(dp[1][n - 1]);
}
