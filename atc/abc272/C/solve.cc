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

void supermax(int num, int& n1, int& n2) {
  if (num >= n1) {
    n2 = n1;
    n1 = num;
  } else if (num >= n2) {
    n2 = num;
  }
}

int main() {
  FastIO;
  int e1{-1}, e2{-1};  // even
  int o1{-1}, o2{-1};  // odd

  int n;
  cin >> n;

  rep(_, n) {
    int a;
    cin >> a;

    if (a % 2 == 0) {
      supermax(a, e1, e2);
    } else {
      supermax(a, o1, o2);
    }
  }

  int ans{-1};

  if (e1 >= 0 && e2 >= 0) {
    chmax(ans, e1 + e2);
  }

  if (o1 >= 0 && o2 >= 0) {
    chmax(ans, o1 + o2);
  }

  cout << ans << '\n';
}
