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

int main() {
  FastIO;
  int m, f, r;

  while (cin >> m >> f >> r) {
    if (m == -1 && f == -1 && r == -1) break;
    int total = m + f;

    dump(m, f, total);

    if (m == -1 || f == -1) {
      output('F');
    } else if (total >= 80) {
      output('A');
    } else if (total >= 65) {
      output('B');
    } else if (total >= 50) {
      output('C');
    } else if (total >= 30) {
      output(r >= 50 ? 'C' : 'D');
    } else {
      output('F');
    }
  }
}
