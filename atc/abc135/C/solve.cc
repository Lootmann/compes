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

int main() {
  FastIO;
  int n;
  read(n);

  vector<llint> monsters(n + 1), heroes(n);
  read(monsters, heroes);
  dump(monsters, heroes);

  llint total{};

  rep(i, n) {
    if (monsters[i] == heroes[i]) {
      total += heroes[i];
    } else if (monsters[i] > heroes[i]) {
      total += heroes[i];
    } else {
      total += monsters[i];
      heroes[i] -= monsters[i];

      // attack next monster
      if (monsters[i + 1] == heroes[i]) {
        total += monsters[i + 1];
        monsters[i + 1] = 0;
      } else if (monsters[i + 1] > heroes[i]) {
        total += heroes[i];
        monsters[i + 1] -= heroes[i];
      } else {
        // eliminate monsters
        total += monsters[i + 1];
        monsters[i + 1] = 0;
      }
    }
  }

  output(total);
}
