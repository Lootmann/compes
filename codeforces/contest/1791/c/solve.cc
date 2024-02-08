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
  string bit;
  cin >> n >> bit;

  int cnt{};
  rep(i, n / 2) {
    char head = bit[i];
    char tail = bit[n - i - 1];
    if ((head == '1' && tail == '0') || (head == '0' && tail == '1')) {
      cnt += 2;
    } else {
      break;
    }
  }

  out(n - cnt);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
