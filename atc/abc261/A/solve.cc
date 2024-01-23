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

  int l1, r1, l2, r2;
  cin >> l1 >> r1 >> l2 >> r2;

  if (r1 <= l2) die(0);
  if (r2 <= l1) die(0);

  vector<int> cells(101, 0);
  for (int i = l1; i <= r1; ++i) {
    cells[i]++;
  }
  for (int i = l2; i <= r2; ++i) {
    cells[i]++;
  }

  int cnt{};
  rep(i, 101) {
    if (cells[i] >= 2) cnt++;
  }
  output(max(cnt - 1, 0));
}
