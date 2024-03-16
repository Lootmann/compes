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

using P = pair<set<int>, bool>;
using ci = const int;

const int SIZE = 10'005;

void update(vector<P>& dp, ci a, ci b, ci idx) {
  rep(i, SIZE) {
    if (dp[i].second && dp[i].first.count(idx)) {
      dp[a + i].first.insert(idx + 1);
      dp[a + i].second = true;
      dp[b + i].first.insert(idx + 1);
      dp[b + i].second = true;
    }
  }
}

int main() {
  int n, x;
  cin >> n >> x;

  vector<P> dp(SIZE);

  rep(i, n) {
    int a, b;
    cin >> a >> b;

    if (i == 0) {
      dp[a] = {{1}, true};
      dp[b] = {{1}, true};
    } else {
      update(dp, a, b, i);
    }
  }

  if (dp[x].first.count(n) && dp[x].second) {
    cout << "Yes" << el;
  } else {
    cout << "No" << el;
  }
}
