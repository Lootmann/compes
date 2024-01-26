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
  string s;
  cin >> s;

  int left{}, right{};

  int n;
  cin >> n;
  rep(_, n) {
    string op;
    cin >> op;

    if (op == "print") {
      cin >> left >> right;
      for (int i = left; i <= right; ++i) cout << s[i];
      cout << '\n';

    } else if (op == "reverse") {
      cin >> left >> right;

      string rev = s.substr(left, right - left + 1);
      reverse(rev.begin(), rev.end());

      for (int i = left; i <= right; ++i) {
        s[i] = rev[i - left];
      }
    } else {
      cin >> left >> right;

      string r;
      cin >> r;

      for (int i = 0; i <= right - left; ++i) {
        s[i + left] = r[i];
      }
    }
  }
}
