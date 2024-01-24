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

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;
  string s;
  cin >> s;

  int n = (int)s.size() + 1;
  vector<int> gt(n, 0), lt(n, 0);

  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == '<') {
      gt[i + 1] = gt[i] + 1;
    }
  }

  for (int i = n - 2; i >= 0; --i) {
    if (s[i] == '>') {
      lt[i] = lt[i + 1] + 1;
    }
  }

  llint cnt{};
  rep(i, n) cnt += max(gt[i], lt[i]);
  output(cnt);
}
