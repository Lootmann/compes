#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define INTi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;
using P = pair<string, pair<int, int>>;

bool compare(const P& l, const P& r) {
  if (l.first < r.first) return true;
  if (l.first > r.first) return false;
  if (l.second.first > r.second.first) return true;
  return false;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<P> restraunt(n);
  rep(i, n) {
    string s;
    int p;
    cin >> s >> p;
    restraunt[i] = make_pair(s, make_pair(p, i));
  }

  sort(restraunt.begin(), restraunt.end(), compare);

  rep(i, n) {
    cout << restraunt[i].second.second + 1 << '\n';
  }
}
