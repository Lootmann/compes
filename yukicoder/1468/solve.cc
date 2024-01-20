#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define repa(i, a, n) for (int i = a; (int)(i) < (n); (++i))
#define rrep(i, n) for (int i = (n - 1); (int)i >= 0; --i)
#define rrepa(i, a, n) for (int i = a; (int)i >= 0; --i)
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

int idx(string s) {
  char c = s.front();
  if (c == 'R') return 0;
  if (c == 'O') return 1;
  if (c == 'Y') return 2;
  if (c == 'G') return 3;
  if (c == 'C') return 4;
  if (c == 'B') return 5;
  return 6;
}

int main() {
  FastIO;
  int n;
  read(n);

  vector<int> shop(7, 0);
  rep(_, n) {
    string a;
    read(a);
    shop[idx(a)]++;
  }
  rep(_, n - 1) {
    string a;
    read(a);
    shop[idx(a)]--;
  }

  dump(shop);

  rep(i, 7) {
    if (shop[i] == 1) {
      if (i == 0) output("Red");
      if (i == 1) output("Orange");
      if (i == 2) output("Yellow");
      if (i == 3) output("Green");
      if (i == 4) output("Cyan");
      if (i == 5) output("Blue");
      if (i == 6) output("Violet");
    }
  }
}
