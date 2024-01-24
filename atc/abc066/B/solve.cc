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

bool is_even_string(const string& s) {
  int len = (int)s.size();
  string left = s.substr(0, len / 2);
  string right = s.substr(len / 2);
  return left == right;
}

int main() {
  FastIO;

  string s;
  cin >> s;

  int len = (int)s.size();
  int max_len{1};

  rep(i, len) {
    int idx = len - i - 1;
    string part = s.substr(0, idx);
    if (is_even_string(part)) {
      chmax(max_len, idx);
    }
  }

  output(max_len);
}
