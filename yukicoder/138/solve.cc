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

struct Version {
  int a;
  int b;
  int c;
};

Version get_version(string s) {
  vector<int> dot;
  rep(i, (int)s.size()) {
    if (s[i] == '.') dot.push_back(i);
  }

  Version v;
  v.a = stoi(s.substr(0, dot[0]));
  v.b = stoi(s.substr(dot[0] + 1, dot[1] - dot[0]));
  v.c = stoi(s.substr(dot[1] + 1));
  return v;
}

int main() {
  FastIO;
  string s, t;
  cin >> s >> t;

  Version a = get_version(s);
  Version b = get_version(t);

  if (a.a > b.a) die("YES");
  if (a.a == b.a && a.b > b.b) die("YES");
  if (a.a == b.a && a.b == b.b && a.c >= b.c) die("YES");
  output("NO");
}
