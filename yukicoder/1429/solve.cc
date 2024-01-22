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

int main() {
  FastIO;
  int d1{}, d2{};

  // (p, q) = (0, 0)
  cout << "? 0 0" << endl;
  read(d1);

  // (p, q) = (100, 0)
  cout << "? 100 0" << endl;
  read(d2);

  set<pair<int, int>> setD;

  // calc
  rep(i, 101) {
    rep(j, 101) {
      int dist = pow(i - 0, 2) + pow(j - 0, 2);
      if (dist == d1) {
        setD.insert(make_pair(i, j));
      }
    }
  }

  rep(i, 101) {
    rep(j, 101) {
      int dist = pow(i - 100, 2) + pow(j, 2);
      if (dist == d2) {
        if (setD.contains(make_pair(i, j))) {
          cout << "! " << i << ' ' << j << endl;
          return 0;
        }
      }
    }
  }
}
