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
  string s;
  cin >> s;

  bool is_failed{false};
  rep(i, (int)s.size() - 1) {
    if (s.substr(i, 2) == "WA") is_failed = true;
  }
  rep(i, (int)s.size() - 2) {
    string k = s.substr(i, 3);
    if (k == "TLE") is_failed = true;
    if (k == "MLE") is_failed = true;
  }
  if (!is_failed)
    out("Done!");
  else
    out("Failed...");
}
