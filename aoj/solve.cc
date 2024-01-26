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

void show_rectangle(int h, int w) {
  rep(_, w) cout << "#";
  cout << '\n';

  rep(i, h - 2) {
    cout << "#";
    rep(j, w - 2) cout << ".";
    cout << "#" << '\n';
  }

  rep(_, w) cout << "#";
  cout << '\n';
  return;
}

int main() {
  FastIO;
  vector<pair<int, int>> vp;
  int h, w;

  while (cin >> h >> w) {
    if (h == 0 && w == 0) break;
    vp.push_back(make_pair(h, w));
  }

  int len = (int)vp.size();
  rep(i, len) {
    show_rectangle(vp[i].first, vp[i].second);
    if (i != len - 1) cout << '\n';
  }
}
