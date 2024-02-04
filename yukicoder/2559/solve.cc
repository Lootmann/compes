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
template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;

  int n, x;
  cin >> n >> x;

  vector<int> rights(x, 0);
  rep(_, n) {
    int a, b;
    cin >> a >> b;
    a--;

    int l = b;
    for (int i = a; i >= 0; --i) {
      chmax(rights[i], l--);
    }

    l = b;
    for (int i = a; i < x; ++i) {
      chmax(rights[i], l--);
    }
  }

  rep(i, x) {
    cout << rights[i] << (i == x - 1 ? '\n' : ' ');
  }
}
