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

void solve() {
  int n;
  cin >> n;

  llint sum_of_sqares{}, square_or_sum{};
  for (int i = 1; i <= n; ++i) {
    sum_of_sqares += i * i;
    square_or_sum += i;
  }

  dump(sum_of_sqares, square_or_sum * square_or_sum);
  output(square_or_sum * square_or_sum - sum_of_sqares);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
