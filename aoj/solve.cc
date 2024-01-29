#include <bits/stdc++.h>
#include <math.h>
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

void solve() {
  double x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  double x1_2 = x1 * x1, x2_2 = x2 * x2, x3_2 = x3 * x3;
  double y1_2 = y1 * y1, y2_2 = y2 * y2, y3_2 = y3 * y3;

  double xy1 = x1_2 + y1_2;
  double xy2 = x2_2 + y2_2;
  double xy3 = x3_2 + y3_2;

  double diff_x12 = x1 - x2;
  double diff_x23 = x2 - x3;
  double diff_x31 = x3 - x1;

  double diff_y12 = y1 - y2;
  double diff_y23 = y2 - y3;
  double diff_y31 = y3 - y1;

  double p = xy1 * diff_y23 + xy2 * diff_y31 + xy3 * diff_y12;
  p /= (diff_x12 * diff_y23 - diff_x23 * diff_y12);
  p /= 2;

  double q = xy1 * diff_x23 + xy2 * diff_x31 + xy3 * diff_x12;
  q /= (diff_x23 * diff_y12 - diff_x12 * diff_y23);
  q /= 2;

  double r = sqrtl(powl(x1 - p, 2) + powl(y1 - q, 2));

  cout << p << ' ' << q << ' ' << r << '\n';
}

int main() {
  FastIO;
  int t;
  cin >> t;
  cout << fixed << setprecision(3);
  rep(_, t) solve();
}
