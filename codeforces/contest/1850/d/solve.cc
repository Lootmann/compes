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
  int n, k;
  cin >> n >> k;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];
  sort(all(ai));

  int max_cnt{1}, cnt{};

  rep(i, n - 1) {
    int dist = abs(ai[i] - ai[i + 1]);
    if (dist <= k) {
      if (cnt == 0) {
        cnt = 2;
      } else {
        cnt++;
      }
    } else {
      cnt = 0;
    }
    chmax(max_cnt, cnt);
  }

  cout << ai.size() - max_cnt << '\n';
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
