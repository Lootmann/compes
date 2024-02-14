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
using llint  = unsigned long long int;

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

  vector<llint> vi(5, 0);
  rep(i, n) {
    string s;
    cin >> s;

    if (s[0] == 'M')
      vi[0]++;
    else if (s[0] == 'A')
      vi[1]++;
    else if (s[0] == 'R')
      vi[2]++;
    else if (s[0] == 'C')
      vi[3]++;
    else if (s[0] == 'H')
      vi[4]++;
  }

  int c{};
  rep(i, 5) {
    if (vi[i] >= 1) c++;
  }
  if (c < 3) die(0);

  llint cnt{};
  for (int i = 0; i < 5; ++i) {
    for (int j = i + 1; j < 5; ++j) {
      for (int k = j + 1; k < 5; ++k) {
        cnt += vi[i] * vi[j] * vi[k];
      }
    }
  }
  out(cnt);
}
