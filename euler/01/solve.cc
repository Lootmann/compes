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

llint sum(llint n) {
  return n * (n + 1) / 2;
}

llint f(llint target, llint x) {
  llint p = target / x;
  llint ans = x * sum(p);
  dump(ans);
  return ans;
}

void solve() {
  int n{};
  cin >> n;

  llint sum{};
  sum += f(n - 1, 3);
  sum += f(n - 1, 5);
  sum -= f(n - 1, 15);

  cout << sum << endl;
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
