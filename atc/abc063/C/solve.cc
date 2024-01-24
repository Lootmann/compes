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
  int n;
  cin >> n;

  int total{};
  vector<int> si(n);
  rep(i, n) {
    cin >> si[i];
    total += si[i];
  }

  if (total % 10 != 0) die(total);

  int ans{};
  sort(si.begin(), si.end());

  rep(i, n) {
    if ((total - si[i]) % 10 != 0) {
      chmax(ans, total - si[i]);
    }
  }

  output(ans);
}
