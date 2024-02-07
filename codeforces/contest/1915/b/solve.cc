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
  int a{}, b{}, c{};
  rep(_, 3) {
    string line;
    cin >> line;
    for (auto ch : line) {
      if (ch == 'A') a++;
      if (ch == 'B') b++;
      if (ch == 'C') c++;
    }
  }

  if (a == 2)
    out('A');
  else if (b == 2)
    out('B');
  else
    out('C');
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
