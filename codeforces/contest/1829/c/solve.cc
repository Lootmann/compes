#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

using llint = long long int;

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

#define MAX 2 * 100000 + 1

void solve() {
  int n;
  cin >> n;

  llint min_time{MAX};
  llint one{MAX}, two{MAX};

  rep(_, n) {
    llint ti;
    string s;
    cin >> ti >> s;

    if (s == "11") {
      chmin(min_time, ti);
    }
    if (s == "10") {
      chmin(one, ti);
    }
    if (s == "01") {
      chmin(two, ti);
    }
  }

  if (min_time == MAX) {
    if (one == MAX || two == MAX) {
      out(-1);
    } else {
      out(one + two);
    }
  } else {
    if (one == MAX || two == MAX) {
      out(min_time);
    } else {
      out(min(min_time, one + two));
    }
  }
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
