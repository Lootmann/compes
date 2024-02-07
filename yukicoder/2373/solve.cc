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

bool is_oa(char ch) {
  return ch == 'a' || ch == 'o';
}

bool is_question(char ch) {
  return ch == '?';
}

// wa, wo, n
int main() {
  FastIO;
  int n;
  string s;
  cin >> n >> s;

  rep(i, n) {
    // w(o|a|?)
    if (s[i] == 'w') {
      if (i == n - 1) die("No");

      char nx = s[i + 1];
      // w?
      if (nx == '?') {
        s[i + 1] = 'a';

      }
      // wo,wa
      else if (nx != 'a' && nx != 'o' && nx != '?') {
        die("No");
      }
    }

    // ?(o|a)
    else if (s[i] == 'o' || s[i] == 'a') {
      if (i == 0) die("No");

      char pv = s[i - 1];
      if (pv != 'w' && pv != '?') {
        die("No");
      }
    }
  }

  out("Yes");
}
