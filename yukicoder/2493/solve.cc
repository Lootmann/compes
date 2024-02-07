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

struct GoodPoint {
  double dist;
  int x;
  int y;

  GoodPoint(double e, int _x, int _y) : dist(e), x(_x), y(_y) {}
};

bool compare(const GoodPoint& a, const GoodPoint& b) {
  if (a.dist < b.dist) return true;
  return false;
}

double euclid(int x1, int y1, int x2, int y2) {
  return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
  FastIO;
  int q;
  cin >> q;

  rep(_, q) {
    int d, k;
    cin >> d >> k;

    vector<GoodPoint> good_points;

    for (int x = -d; x <= d; ++x) {
      for (int y = -d; y <= d; ++y) {
        double manhattan = abs(x) + abs(y);

        if (manhattan == d) {
          GoodPoint p(x * x + y * y, x, y);
          good_points.push_back(p);
        }
      }
    }

    if (k > (int)good_points.size()) {
      output("No");
    } else {
      sort(good_points.begin(), good_points.end(), compare);
      output("Yes");
      cout << good_points[k - 1].x << ' ' << good_points[k - 1].y << '\n';
    }
  }
}
