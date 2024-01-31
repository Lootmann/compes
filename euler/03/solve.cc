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
  llint n;
  cin >> n;

  set<llint> st;
  for (llint i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      st.insert(i);
      n /= i;
    }
  }

  if (n != 1) {
    st.insert(n);
  }

  dump(st);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
