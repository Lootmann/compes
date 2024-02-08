#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

using llint = long long int;

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

bool can_split(int n, int t) {
  if (n == t) return true;
  if (n % 3 != 0) return false;
  return can_split(n / 3, t) || can_split(2 * n / 3, t);
}

void solve() {
  int nugget, target;
  cin >> nugget >> target;

  if (can_split(nugget, target)) {
    out("YES");
  } else {
    out("NO");
  }
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
