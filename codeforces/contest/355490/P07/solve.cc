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

bool is_vowel(char ch) {
  return ch == 'a' || ch == 'o' || ch == 'y' || ch == 'e' || ch == 'u' ||
         ch == 'i';
}

void solve() {
  string s;
  cin >> s;

  transform(s.begin(), s.end(), s.begin(), ::tolower);

  vector<char> vc;
  for (auto ch : s) {
    if (!is_vowel(ch)) {
      vc.push_back(ch);
    }
  }

  dump(vc);

  for (auto ch : vc) {
    cout << '.' << ch;
  }
  cout << '\n';
}

int main() {
  FastIO;
  int t{1};
  while (t--) solve();
}
