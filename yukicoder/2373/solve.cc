#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define repa(i, a, n) for (int i = a; (int)i < n; ++i)
#define rrep(i, n) for (int i = n; (int)i >= 0; --i)
#define rrepa(i, a, n) for (int i = a; (int)i >= n; --i)
#define EACH(x, a) for (auto& x : a)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)

template <class A> void read(vector<A>& v);
template <class A, size_t S> void read(array<A, S>& a);
template <class T> void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T> void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A> void read(vector<A>& x) {
  EACH(a, x) read(a);
}
template <class A, size_t S> void read(array<A, S>& x) {
  EACH(a, x) read(a);
}
template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

bool valid(char ch) {
  return ch == 'w' || ch == 'a' || ch == 'o' || ch == 'n' || ch == '?';
}

void solve(string& s, int len) {
  rep(i, len) {
    char cur = s[i];

    if (cur == 'a' || cur == 'o') {
      if (i == 0) die("No");

      if (s[i - 1] != 'w' && s[i - 1] != '?') {
        dump(i, s[i - 1]);
        die("No");
      }

    }

    // w (a|o)
    else if (cur == 'w') {
      if (i == len - 1) die("No");
      char nxt = s[i + 1];

      if (nxt != 'a' && nxt != 'o' && nxt != '?') {
        die("No");
      }

      if (nxt == '?') {
        s[i + 1] = 'a';  // fixed
      }

    }

    // except waon?
    else if (cur != '?' && cur != 'n') {
      die("No");
    }
  }
}

// wa wo n
int main() {
  FastIO;
  int n;
  read(n);

  string s;
  read(s);

  solve(s, n);

  output("Yes");
}
