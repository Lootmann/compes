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

void solve() {
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  int odd_parity = ai[0] % 2;
  int even_parity = ai[1] % 2;

  bool is_good{true};

  rep(i, n) {
    int parity = ai[i] % 2;

    if (i % 2 == 0) {
      is_good &= parity != odd_parity;
    } else {
      is_good &= parity != even_parity;
    }

    if (!is_good) {
      out("NO");
      return;
    }
  }

  out("YES");
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
