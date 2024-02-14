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

  vector<int> ai(n), bi(m);
  rep(i, n) cin >> ai[i];
  rep(i, m) cin >> bi[i];

  vector<int> di;
  for (auto a : ai) di.push_back(a);
  for (auto b : bi) di.push_back(b);
  sort(all(di));

  map<int, int> pos;
  rep(i, n + m) {
    pos[di[i]] = i + 1;
  }

  dump(pos);

  rep(i, n) cout << pos[ai[i]] << (i == n - 1 ? '\n' : ' ');
  rep(i, m) cout << pos[bi[i]] << (i == m - 1 ? '\n' : ' ');
}
