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

int main() {
  FastIO;

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> students(n), checkpoints(m);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    students[i] = make_pair(a, b);
  }

  rep(i, m) {
    int c, d;
    cin >> c >> d;
    checkpoints[i] = make_pair(c, d);
  }

  rep(i, n) {
    int min_dist{INFi}, ans{51};

    pair<int, int> s = students[i];
    rep(j, m) {
      pair<int, int> p = checkpoints[j];
      int dist = abs(s.first - p.first) + abs(s.second - p.second);

      if (min_dist > dist) {
        min_dist = dist;
        ans = j + 1;
        chmin(ans, j + 1);
      }
    }
    output(ans);
  }
}
