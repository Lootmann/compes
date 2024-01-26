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

  vector<int> hi, wi;
  int h, w;
  while (cin >> h >> w) {
    if (h == 0 && w == 0) break;
    hi.push_back(h);
    wi.push_back(w);
  }

  dump(hi);
  dump(wi);

  int len = (int)hi.size();
  rep(i, len) {
    rep(_, hi[i]) {
      rep(__, wi[i]) cout << "#";
      cout << '\n';
    }
    if (i != len - 1) cout << '\n';
  }
}
