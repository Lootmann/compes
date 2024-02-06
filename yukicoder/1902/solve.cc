#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << msg << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

tuple<double, double> split(string s) {
  int idx = s.find("/");
  double l = stod(s.substr(0, idx));
  double r = stod(s.substr(idx + 1));
  dump(l, r);
  return forward_as_tuple(l, r);
}

int main() {
  FastIO;
  string s;
  cin >> s;

  double a{}, b{};
  tie(a, b) = split(s);

  cout << fixed << setprecision(12);
  output(a / b);
}
