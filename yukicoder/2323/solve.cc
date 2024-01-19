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
  string a, b;
  read(a, b);

  int aa = (int)a.size();
  int bb = (int)b.size();

  if (aa > bb) {
    rep(i, aa - bb) b = '0' + b;
  } else if (aa < bb) {
    rep(i, bb - aa) a = '0' + a;
  }

  vector<int> carryup(max(aa, bb), 0);
  rep(i, max(aa, bb)) {
    if (a[i] == '1') carryup[i]++;
    if (b[i] == '1') carryup[i]++;
  }

  string s{};
  rep(i, max(aa, bb)) {
    if (carryup[i] == 1)
      s = s + '1';
    else
      s = s + '0';
  }

  int ans{};
  for (auto ch : s) {
    ans *= 2;
    if (ch == '1') {
      ans += 1;
    }
  }

  output(ans);
}
