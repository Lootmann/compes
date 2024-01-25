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

int main() {
  FastIO;
  int N, M;
  cin >> N >> M;

  vector<vector<int>> sw(10);
  rep(i, M) {
    int k;
    cin >> k;

    rep(__, k) {
      int s;
      cin >> s;
      s--;
      sw[i].push_back(s);
    }
  }

  vector<int> ps(10, 0);
  rep(i, M) {
    int p;
    cin >> p;
    ps[i] = p;
  }

  int ans{};
  for (int bit = 0; bit < (1 << N); ++bit) {
    int lighton{0};
    for (int m = 0; m < M; ++m) {
      int cnt{};
      for (auto s : sw[m]) {
        if (bit & (1 << s)) cnt++;
      }
      if (cnt % 2 == ps[m]) lighton++;
    }

    if (lighton == M) {
      ans++;
    }
  }
  dump(ps);
  output(ans);
}
