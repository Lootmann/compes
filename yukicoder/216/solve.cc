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
  int n;
  cin >> n;
  vector<int> ai(n), bi(n);
  rep(i, n) cin >> ai[i];
  rep(i, n) cin >> bi[i];

  vector<int> player_score(101, 0);
  rep(i, n) {
    player_score[bi[i]] += ai[i];
  }

  int k_kun = player_score[0];

  for (int i = 1; i <= 100; ++i) {
    if (k_kun < player_score[i]) die("NO");
  }

  output("YES");
}
