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
  string s;

  vector<int> chars(26, 0);

  while (getline(cin, s)) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (auto ch : s) {
      if ('a' <= ch && ch <= 'z') {
        chars[ch - 'a']++;
      }
    }
  }

  rep(i, 26) {
    cout << (char)(i + 'a') << " : " << chars[i] << '\n';
  }
}
