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

void solve() {
  int n;
  string s;
  cin >> n >> s;

  vector<llint> turn_scores;
  llint sum{};
  rep(i, n) {
    if (s[i] == 'L') {
      turn_scores.push_back((n - 1 - i) - i);
      sum += i;
    } else {
      turn_scores.push_back(i - (n - 1 - i));
      sum += n - i - 1;
    }
  }

  sort(rall(turn_scores));
  dump(turn_scores);

  rep(i, n) {
    llint score = turn_scores[i];
    if (score > 0) {
      sum += score;
    }
    cout << sum << ' ';
  }
  cout << '\n';
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
