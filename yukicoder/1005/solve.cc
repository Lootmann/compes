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
  string s, t;
  cin >> s >> t;

  if (t.size() == 1) {
    if (s.find(t) != string::npos) {
      die(-1);
    } else {
      die(0);
    }
  }

  dump(s, t);

  int idx{}, cnt{};

  while (idx <= (int)s.size()) {
    if (s.substr(idx, t.size()) == t) {
      cnt++;
      idx = idx + (int)t.size() - 1;
    } else {
      idx++;
    }
  }

  output(cnt);
}
