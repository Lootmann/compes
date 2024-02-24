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

using vs = vector<string>;

namespace me {

int diff(const vs& s, const vs& t, const int n) {
  int cnt{};
  rep(h, n) rep(w, n) {
    if (s[h][w] != t[h][w]) cnt++;
  }
  return cnt;
}

void rot(vs& s, const int n) {
  vector<string> res(n, string(n, '.'));
  rep(h, n) rep(w, n) res[w][n - h - 1] = s[h][w];
  s = res;
}

int calc(const vs& s, const vs& t, const int n, int rot) {
  vector<string> tmp = s;
  int cost{};

  // rot cost
  if (rot == 3)
    cost += 1;
  else
    cost += rot;

  // rot
  rep(_, rot) me::rot(tmp, n);

  cost += me::diff(tmp, t, n);
  return cost;
}
}  // namespace me

int main() {
  int n;
  cin >> n;

  vector<string> s(n), t(n);
  rep(i, n) cin >> s[i];
  rep(i, n) cin >> t[i];

  int ans{500 * 500 + 1};

  rep(i, 4) {
    int cost{};
    cost = me::calc(s, t, n, i);
    chmin(ans, cost);
  }

  cout << ans << el;
}
