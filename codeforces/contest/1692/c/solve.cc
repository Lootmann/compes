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

int dh[]{1, 1, -1, -1};
int dw[]{1, -1, 1, -1};

bool is_inbound(int y, int x) {
  return 0 <= y && y < 8 && 0 <= x && x < 8;
}

void solve() {
  vector<string> vs(8);
  rep(i, 8) cin >> vs[i];

  int y{}, x{};
  int max_cnt{};

  rep(h, 8) {
    rep(w, 8) {
      int cnt{};
      rep(k, 4) {
        int nh = h + dh[k];
        int nw = w + dw[k];

        if (!is_inbound(nh, nw)) continue;
        if (vs[nh][nw] == '#') {
          cnt++;
        }
      }

      if (chmax(max_cnt, cnt)) {
        y = h + 1;
        x = w + 1;
      }
    }
  }

  cout << y << ' ' << x << '\n';
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
