#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do {cout << msg << endl;exit(0);} while (0)
#define el '\n'

#define all(k)  k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> dish;
  rep(_, m) {
    int a, b;
    cin >> a >> b;
    dish.push_back({a, b});
  }

  int k;
  cin >> k;
  vector<pair<int, int>> conditions;
  rep(_, k) {
    int c, d;
    cin >> c >> d;
    conditions.push_back({c, d});
  }

  int ans{};

  for (int bit = 0; bit < (1 << k); ++bit) {
    vector<bool> fills(n);
    for (int i = 0; i < k; ++i) {
      auto [left, right] = conditions[i];
      if (bit & (1 << i)) {
        fills[left] = 1;
      } else {
        fills[right] = 1;
      }
    }

    int cnt{};
    for (auto [a, b] : dish) {
      if (fills[a] && fills[b]) {
        cnt++;
      }
    }

    chmax(ans, cnt);
  }

  cout << ans << el;
}
