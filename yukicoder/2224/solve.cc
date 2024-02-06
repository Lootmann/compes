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
using ullint = unsigned long long int;

int main() {
  FastIO;

  string s;
  cin >> s;

  ullint mx{1};
  rep(_, 32) mx *= 2;
  dump(mx);

  if (s.front() == 'x') {
    ullint t = stoull(s.substr(1));
    output(mx - t);
  } else {
    output(s);
  }
}
