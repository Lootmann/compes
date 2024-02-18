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
  int n, m, x;
  cin >> n >> m >> x;

  // cost, power
  vector<pair<int, vector<int>>> vp(n);

  rep(i, n) {
    int c;
    cin >> c;

    vector<int> ai(m);
    rep(j, m) cin >> ai[j];

    vp[i].first = c;
    vp[i].second = ai;
  }

  int min_cost{INFi};

  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> tmp(m);
    int cost{};

    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        cost += vp[i].first;
        rep(j, m) tmp[j] += vp[i].second[j];
      }
    }

    bool good_brain{true};
    for (auto t : tmp) {
      if (t < x) {
        good_brain = false;
      }
    }

    if (good_brain) {
      chmin(min_cost, cost);
    }
  }

  if (min_cost == INFi) {
    out(-1);
  } else {
    out(min_cost);
  }
}
