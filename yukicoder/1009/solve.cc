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

double f(double x, double a, double b) {
  return (x - a) * (x - b);
}

double s(double n, double a, double b) {
  double area{};
  rep(ki, n) {
    double width = (b - a) / n;
    double x = a + (b - a) * ki / n;
    area += abs(f(x, a, b)) * width;
  }
  return area;
}

int main() {
  FastIO;
  double a, b;
  cin >> a >> b;

  cout << fixed << setprecision(8);
  cout << s(10000, a, b) << endl;

  double ans{36};
  cout << "   n |        calc |        true |   accurate " << '\n';
  cout << "-----+-------------+-------------+------------" << '\n';
  for (int n = 1000; n <= 1010; ++n) {
    double area = s(n, a, b);
    cout << n << " | ";
    cout << area << " | ";
    cout << ans << " | ";
    cout << area * 100 / ans << endl;
  }
}
