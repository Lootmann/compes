#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
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
  llint n, c;
  cin >> n >> c;

  vector<llint> ai(n);
  rep(i, n) cin >> ai[i];

  int left{}, right{};
  pair<int, int> best_range{-1, -1};
  llint best{}, current{};

  if (c > 0) {
    rep(i, n) {
      if (ai[i] >= 0) {
        current += ai[i];
        if (left == 0) {
          left = i;
        }
      } else {
        if (chmax(best, current)) {
          best_range = {left, i - 1};
        }

        left = 0;
        current = 0;
      }
    }

  } else if (c < 0) {
    llint best{INFll}, current{};

    rep(i, n) {
      if (ai[i] <= 0) {
        current += ai[i];
        if (left == 0) {
          left = i;
        }
      } else {
        if (chmin(best, current)) {
          best_range = {left, i - 1};
        }
        left = 0;
        current = 0;
      }
    }
  }

  llint sum{};
  rep(i, n) {
    if (best_range.first <= i && i <= best_range.second) {
      sum += ai[i] * c;
    } else {
      sum += ai[i];
    }
  }
  cout << sum << el;
}
