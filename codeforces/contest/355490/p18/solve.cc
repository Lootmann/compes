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
#define INTi 1 << 30
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
  int n;
  cin >> n;

  if (n % 2 == 0) {
    int two = n / 2;
    cout << two << '\n';
    rep(i, two) cout << 2 << (i == two - 1 ? '\n' : ' ');
  } else {
    n -= 3;
    int three = 1;
    int two = n / 2;

    cout << two + three << '\n';
    cout << 3;
    rep(i, two) cout << ' ' << 2;
    cout << '\n';
  }
}
