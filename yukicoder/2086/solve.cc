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

string zero_padding(string s, int n) {
  string res{s};
  rep(i, n - (int)s.size()) {
    res = "0" + res;
  }
  return res;
}

int main() {
  FastIO;
  string a, b;
  cin >> a >> b;

  if (a.size() < b.size()) {
    a = zero_padding(a, (int)b.size());
  } else if (a.size() > b.size()) {
    b = zero_padding(b, (int)a.size());
  }
  dump(a, b);

  int carryup{}, len = (int)a.size();
  for (int i = len - 1; i >= 0; --i) {
    int n = int(a[i] - '0') + int(b[i] - '0') + carryup;
    carryup = 0;
    if (n >= 10) carryup = 1;
    a[i] = char(n % 10 + '0');
  }

  if (carryup == 1) {
    a = "1" + a;
  }

  dump(a);
  output(a);
}
