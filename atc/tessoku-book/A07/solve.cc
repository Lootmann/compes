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
  int d, n;
  cin >> d >> n;

  vector<int> acc(d + 1);

  rep(i, n) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    acc[l]++;
    acc[r + 1]--;
  }

  for (int i = 1; i <= d; i++) {
    acc[i] += acc[i - 1];
  }

  rep(i, d) {
    output(acc[i]);
  }
}
