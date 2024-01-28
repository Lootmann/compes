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

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> xi(n);
  rep(i, n) cin >> xi[i];

  int m;
  cin >> m;
  vector<int> ai(n);
  rep(i, m) {
    cin >> ai[i];
    ai[i]--;
  }

  rep(i, m) {
    int idx = ai[i];
    // rigth
    if (idx == n - 1) {
      if (xi[idx] < 2019) {
        xi[idx]++;
      }
    } else {
      if (xi[idx] + 1 < xi[idx + 1]) {
        xi[idx]++;
      }
    }
    dump(idx, xi);
  }

  rep(i, n) {
    output(xi[i]);
  }
}
