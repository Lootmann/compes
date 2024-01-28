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

string opt_sort(string& s) {
  vector<int> lower(26, 0), upper(26, 0), digit(10, 0);
  int n = (int)s.size();
  rep(i, n) {
    if (islower(s[i])) lower[s[i] - 'a']++;
  }
  rep(i, n) {
    if (isupper(s[i])) upper[s[i] - 'A']++;
  }
  rep(i, n) {
    if (isdigit(s[i])) digit[s[i] - '0']++;
  }

  string res{};

  rep(i, 26) {
    rep(j, lower[i]) res += (char)('a' + i);
  }

  rep(i, 26) {
    rep(j, upper[i]) res += (char)('A' + i);
  }

  rep(i, 10) {
    rep(j, digit[i]) res += (char)('0' + i);
  }

  return res;
}

int main() {
  FastIO;
  string line;
  while (cin >> line) {
    if (line == "#") return 0;
    line = opt_sort(line);
    output(line);
  }
}
