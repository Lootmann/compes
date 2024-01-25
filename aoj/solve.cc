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
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

void solve(int n) {
  vector<double> si(n);
  rep(i, n) cin >> si[i];

  double average{};
  rep(i, n) {
    average += si[i];
  }
  average /= n;

  double variance{};
  rep(i, n) {
    variance += powl((si[i] - average), 2);
  }
  double std = sqrt(variance / n);

  cout << fixed << setprecision(8);
  output(std);
}

int main() {
  FastIO;
  while (true) {
    int t;
    cin >> t;
    if (t == 0) return 0;
    solve(t);
  }
}
