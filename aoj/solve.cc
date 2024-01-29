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

tuple<double, double> split(string s) {
  int idx{};
  rep(i, (int)s.size()) {
    if (s[i] == ',') idx = i;
  }
  double x = stod(s.substr(0, idx));
  double y = stod(s.substr(idx + 1));
  return tuple(x, y);
}

int main() {
  FastIO;
  string line;

  double px{0.0}, py{0.0}, deg{0.0};
  while (cin >> line) {
    double dist, d;
    tie(dist, d) = split(line);
    if (dist == 0 && d == 0) break;

    px += dist * sin(deg * (M_PI / 180));
    py += dist * cos(deg * (M_PI / 180));
    deg += d;
  }

  dump("result", px, py);
  output((int)px);
  output((int)py);
}
