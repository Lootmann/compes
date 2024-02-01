#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;
using vi = vector<int>;
using vvi = vector<vi>;
using ci = const int;

void out(const vvi& ans, ci n) {
  rep(h, n) rep(w, n) {
    cout << ans[h][w] << (w == n - 1 ? '\n' : ' ');
  }
}

void solve(const vvi& li, const vvi& ri, int n, ci b1, ci b2, ci b3) {
  vvi ans = li;
  out(ans, n);
}

int main() {
  FastIO;

  int n, b1, b2, b3;
  cin >> n >> b1 >> b2 >> b3;

  // input
  vvi li(n, vi(n, 0)), ri(n, vi(n, 0));
  rep(h, n) rep(w, n) cin >> li[h][w];
  rep(h, n) rep(w, n) cin >> ri[h][w];

  // solver
  solve(li, ri, n, b1, b2, b3);
}
