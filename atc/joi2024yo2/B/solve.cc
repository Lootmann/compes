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

struct Item {
  llint price;
  int type;
};

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  // FIXME: culmulative sum?
  vector<Item> items;
  rep(_, n) {
    llint p;
    int a;
    cin >> p >> a;
    items.push_back(Item{p, a});
  }

  // O(200'000)
  rep(_, q) {
    // l <= 200'000, r <= 200'000
    llint t, l, r;
    cin >> t >> l >> r;
    l--, r--;

    llint sum{};
    for (int i = l; i <= r; ++i) {
      auto item = items[i];
      if (item.type == t) {
        sum += item.price / 2;
      } else {
        sum += item.price;
      }
    }
    cout << sum << el;
  }
}
