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

using VI = vector<int>;

double manhattan(const VI& xi, const VI& yi, const int len) {
  double dist{};
  rep(i, len) dist += abs(xi[i] - yi[i]);
  return dist;
}

double euclid(const VI& xi, const VI& yi, const int len) {
  double dist{};
  rep(i, len) {
    dist += abs(xi[i] - yi[i]) * abs(xi[i] - yi[i]);
  }
  return sqrt(dist);
}

long double euclid3(const VI& xi, const VI& yi, const int len) {
  long double dist{};
  rep(i, len) {
    dist += powl(abs(xi[i] - yi[i]), 3);
  }
  return cbrt(dist);
}

double chevshev(const VI& xi, const VI& yi, const int len) {
  int dist{};
  rep(i, len) {
    chmax(dist, abs(xi[i] - yi[i]));
  }
  return (double)dist;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> xi(n), yi(n);
  rep(i, n) cin >> xi[i];
  rep(i, n) cin >> yi[i];

  cout << fixed << setprecision(6);
  output(manhattan(xi, yi, n));
  output(euclid(xi, yi, n));
  output(euclid3(xi, yi, n));
  output(chevshev(xi, yi, n));
}
