#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

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

using llint = long long int;

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  char op;
  cin >> op;

  vector<llint> wi(m);
  rep(i, m) cin >> wi[i];

  vector<llint> hi(n);
  rep(i, n) cin >> hi[i];

  rep(h, n) {
    rep(w, m) {
      if (op == '+') {
        cout << hi[h] + wi[w] << (w == m - 1 ? '\n' : ' ');
      } else {
        cout << hi[h] * wi[w] << (w == m - 1 ? '\n' : ' ');
      }
    }
  }
}
