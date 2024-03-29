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

bool is_upper(char ch) {
  return 'A' <= ch && ch <= 'Z';
}

int main() {
  FastIO;
  string s;
  cin >> s;

  if (s.size() != 8) die("No");
  if (!is_upper(s.front()) || !is_upper(s.back())) die("No");
  for (int i = 1; i < 7; ++i) {
    if (!('0' <= s[i] && s[i] <= '9')) die("No");
  }

  int num = stoi(s.substr(1, 6));
  if (100000 <= num && num <= 999999)
    output("Yes");
  else
    output("No");
}
