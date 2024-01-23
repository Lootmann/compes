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

int main() {
  FastIO;
  llint n, w;
  cin >> n >> w;

  vector<pair<llint, llint>> cheese(n);
  rep(i, n) {
    llint taste, weight;
    cin >> taste >> weight;
    cheese[i] = make_pair(taste, weight);
  }

  sort(cheese.rbegin(), cheese.rend());

  llint total{};
  rep(i, n) {
    if (w >= 0) {
      total += cheese[i].first * min(w, cheese[i].second);
      w -= cheese[i].second;
    }
  }

  output(total);
}
