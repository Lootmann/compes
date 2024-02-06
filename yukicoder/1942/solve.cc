#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << msg << '\n'
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

int remove_zero(const string& s) {
  int idx{-1};
  rep(i, (int)s.size()) {
    if (s[i] != '0') {
      idx = i;
      break;
    }
  }

  if (idx == -1)
    return 0;
  else
    return stoi(s.substr(idx));
}

int main() {
  FastIO;
  int N;
  cin >> N;

  rep(_, N) {
    string s;
    cin >> s;
    output(remove_zero(s));
  }
}
