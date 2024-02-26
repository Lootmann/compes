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

vector<llint> split(const vector<llint>& fi, int D) {
  int n = (int)fi.size();
  vector<llint> tmp;
  llint now{};

  rep(i, n) {
    if (i != 0 && i % D == 0) {
      tmp.push_back(now);
      now = 0;
    }
    now += fi[i];

    if (i == n - 1) {
      tmp.push_back(now);
    }
  }
  return tmp;
}

int main() {
  llint N, D, P;
  cin >> N >> D >> P;

  vector<llint> fi(N);
  rep(i, N) cin >> fi[i];
  sort(rall(fi));

  llint ans{};
  for (auto cost : split(fi, D)) {
    ans += min(cost, P);
  }
  cout << ans << el;
}
