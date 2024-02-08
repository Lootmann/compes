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

using css = const set<string>;

int count(css& p1, css& p2, css& p3) {
  int cnt{};

  for (auto me : p1) {
    int c{};
    if (p2.find(me) != p2.end()) {
      c++;
    }

    if (p3.find(me) != p3.end()) {
      c++;
    }

    if (c == 0) {
      cnt += 3;
    } else if (c == 1) {
      cnt++;
    }
  }

  return cnt;
}

set<string> get_names(int n) {
  set<string> names;
  rep(_, n) {
    string name;
    cin >> name;
    names.insert(name);
  }
  return names;
}

void solve() {
  int n;
  cin >> n;

  set<string> p1 = get_names(n), p2 = get_names(n), p3 = get_names(n);
  dump(p1, p2, p3);

  int cnt1 = count(p1, p2, p3);
  int cnt2 = count(p2, p3, p1);
  int cnt3 = count(p3, p1, p2);
  cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 << '\n';
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
