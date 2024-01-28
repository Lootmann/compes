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

void solve(int n) {
  vector<llint> ai(n);
  rep(i, n) cin >> ai[i];

  llint ans{INFll};
  for (int bit = 0; bit < (1 << n); ++bit) {
    llint left{}, right{};
    rep(i, n) {
      if (bit & (1 << i)) {
        left += ai[i];
      } else {
        right += ai[i];
      }
    }
    chmin(ans, abs(left - right));
  }
  output(ans);
}

int main() {
  FastIO;
  int n;
  while (cin >> n) {
    if (n == 0) break;
    solve(n);
  }
}
