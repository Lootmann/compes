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
using P = pair<string, int>;

// tagname, score
bool compare(const P& left, const P& right) {
  if (left.second > right.second) return true;
  if (left.second < right.second) return false;
  if (left.first < right.first) return true;
  return false;
}

int main() {
  FastIO;
  int n;
  read(n);

  // name, total score
  map<string, int> mp;

  rep(_, n) {
    int img_no{};
    read(img_no);

    int num, score;
    read(num, score);

    rep(i, num) {
      string tagname;
      read(tagname);
      mp[tagname] += score;
    }
  }

  vector<pair<string, int>> vp;
  for (auto key : mp) {
    vp.push_back(make_pair(key.first, key.second));
  }

  sort(vp.begin(), vp.end(), compare);

  rep(i, min((int)vp.size(), 10)) {
    cout << vp[i].first << ' ' << vp[i].second << endl;
  }
}
