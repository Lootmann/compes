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
using ld = long double;
using P = pair<ld, ld>;
#define mp make_pair

void make_koch(vector<P>& points) {
  vector<P> res{mp(0.0, 0.0)};
  ld theta = M_PI * 60.0 / 180.0;

  // p0 - p1 point pair makes
  //
  // p0 - s - t - u - p1 : five points
  rep(i, (int)points.size() - 1) {
    auto p1 = points[i];
    auto p2 = points[i + 1];
    auto x1 = p1.first, y1 = p1.second;
    auto x2 = p2.first, y2 = p2.second;

    // 3等分線 : s - t - u
    P s = mp((2 * x1 + x2) / 3, (2 * y1 + y2) / 3);
    P t = mp((x1 + 2 * x2) / 3, (y1 + 2 * y2) / 3);

    // calc triangle
    P u;
    u.first = (t.first - s.first) * cos(theta) -
              (t.second - s.second) * sin(theta) + s.first;
    u.second = (t.first - s.first) * sin(theta) +
               (t.second - s.second) * cos(theta) + s.second;

    res.push_back(s);
    res.push_back(u);
    res.push_back(t);
    res.push_back(p2);  // add last point
  }

  points = res;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<P> points;
  points.push_back(P(0, 0));
  points.push_back(P(100, 0));

  rep(_, n) make_koch(points);

  cout << fixed << setprecision(8);
  rep(i, (int)points.size()) {
    auto p = points[i];
    cout << p.first << ' ' << p.second << '\n';
  }
}
