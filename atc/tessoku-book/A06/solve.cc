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
#define INTi 1 << 30
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
  int n, q;
  cin >> n >> q;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  vector<int> acc(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    acc[i + 1] = acc[i] + ai[i];
  }
  dump(ai);
  dump(acc);

  rep(_, q) {
    int left, right;
    cin >> left >> right;
    output(acc[right] - acc[left - 1]);
  }
}
