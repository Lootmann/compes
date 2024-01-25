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
  int n;
  cin >> n;

  int building[4][3][10]{};

  rep(_, n) {
    int b, f, r, v;
    cin >> b >> f >> r >> v;
    b--, f--, r--;
    building[b][f][r] += v;
  }

  rep(b, 4) {
    rep(f, 3) {
      rep(r, 10) {
        cout << ' ' << building[b][f][r];
      }
      cout << '\n';
    }
    if (b != 3) cout << "####################" << '\n';
  }
}
