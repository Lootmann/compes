#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

bool can_regist(const string& s) {
  bool has_lower{false}, has_digit{false}, has_sign{false};

  for (auto ch : s) {
    if ('a' <= ch && ch <= 'z') has_lower = true;
    if (ch == '@' || ch == '$') has_sign = true;
    if ('0' <= ch && ch <= '9') has_digit = true;
  }

  return has_lower && has_sign && has_digit;
}

char replace(char ch) {
  if (ch == 'l') return '1';
  if (ch == 'o') return '0';
  if (ch == 'a') return '@';
  if (ch == 's') return '$';
  return ch;
}

int main() {
  FastIO;

  string s;
  cin >> s;
  int n = (int)s.size();

  set<string> patterns;

  for (int bit = 0; bit < (1 << n); ++bit) {
    string res{};
    rep(i, n) {
      if (bit & (1 << i)) {
        res += replace(s[i]);
      } else {
        res += s[i];
      }
    }

    if (can_regist(res)) {
      patterns.insert(res);
    }
  }

  dump(patterns);
  output(patterns.size());
}
