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

struct Pos {
  int x;
  int y;
};

using llint = long long int;
using vi = vector<int>;
using vp = vector<Pos>;

void out(const vi& orders, const vi& res_x, const vi& res_y) {
  int n = (int)orders.size();

  cout << n << '\n';
  rep(i, n) cout << orders[i] << ' ';
  cout << '\n';

  cout << res_x.size() << '\n';
  for (int i = 0; i < (int)res_x.size(); ++i) {
    cout << res_x[i] << ' ' << res_y[i] << ' ';
  }
  cout << '\n';
}

int manhattan(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

void solve(const vp& src, const vp& dst, vi& orders, vi& res_x, vi& res_y) {
  set<int> rest_orders;
  rep(i, 1000) rest_orders.insert(i);

  int cur_x = 400, cur_y = 400;

  rep(_, 50) {
    int min_dist{900 * 900}, min_idx{};

    // search closest point from cur_x, cur_y
    for (auto i : rest_orders) {
      int dist = manhattan(cur_x, cur_y, src[i].x, src[i].y);

      if (min_dist > dist) {
        min_dist = dist;
        min_idx = i;
      }
    }

    // decide
    rest_orders.erase(min_idx);

    res_x.push_back(src[min_idx].x);
    res_y.push_back(src[min_idx].y);

    res_x.push_back(dst[min_idx].x);
    res_y.push_back(dst[min_idx].y);

    orders.push_back(min_idx + 1);

    // update
    cur_x = dst[min_idx].x;
    cur_y = dst[min_idx].y;
  }
}

int main() {
  FastIO;

  // input
  vector<Pos> origins(1000), dests(1000);
  rep(i, 1000) cin >> origins[i].x >> origins[i].y >> dests[i].x >> dests[i].y;

  // calc
  vi orders, res_x, res_y;
  res_x.push_back(400);
  res_y.push_back(400);

  solve(origins, dests, orders, res_x, res_y);
  res_x.push_back(400);
  res_y.push_back(400);

  // output
  out(orders, res_x, res_y);
}
