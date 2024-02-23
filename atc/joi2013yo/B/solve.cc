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

using vvi = vector<vector<int>>;
using vi = vector<int>;

int counter(const vi& players, map<int, int> mp) {
  for (auto p : players) {
    mp[p]--;
  }

  dump(players);
  dump(mp);

  int sum{};
  for (auto p : players) {
    if (mp[p] == 0) sum += p;
  }

  return sum;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> nums(n, vector<int>(3, 0));
  rep(i, n) rep(j, 3) cin >> nums[i][j];

  // calc
  vector<int> sum(n, 0);
  rep(j, 3) {
    map<int, int> mp;
    rep(i, n) mp[nums[i][j]]++;

    rep(i, n) {
      if (mp[nums[i][j]] - 1 == 0) {
        sum[i] += nums[i][j];
      }
    }
  }

  for (auto s : sum) {
    cout << s << el;
  }
}
