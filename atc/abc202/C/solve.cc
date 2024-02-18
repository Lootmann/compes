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
  int n;
  cin >> n;

  vector<llint> ai(n), bi(n), ci(n);

  for (auto& a : ai) {
    cin >> a;
    a--;
  }
  for (auto& b : bi) {
    cin >> b;
    b--;
  }
  for (auto& c : ci) {
    cin >> c;
    c--;
  }

  vector<llint> counter(n, 0);
  rep(i, n) {
    llint k = bi[ci[i]];
    counter[k]++;
  }

  llint ans{};
  rep(i, n) {
    ans += counter[ai[i]];
  }
  out(ans);
}
