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

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int getRank(int rate) {
  if (rate < 400) return 0;
  if (rate < 800) return 1;
  if (rate < 1200) return 2;
  if (rate < 1600) return 3;
  if (rate < 2000) return 4;
  if (rate < 2400) return 5;
  if (rate < 2800) return 6;
  if (rate < 3200) return 7;
  return 8;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  vector<int> ranks(9, 0);
  rep(i, n) {
    ranks[getRank(ai[i])]++;
  }

  dump(ranks);

  int colors{};
  rep(i, 8) {
    if (ranks[i] > 0) colors++;
  }

  int free_color{ranks[8]};
  dump(colors, free_color);

  // only free colors
  if (colors == 0) {
    cout << 1 << ' ' << min(8, free_color) << '\n';
    return 0;
  }

  cout << colors << ' ' << colors + free_color << '\n';
  return 0;
}
