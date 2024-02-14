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

  vector<int> s(n, -1);
  rep(_, m) {
    int si, ci;
    cin >> si >> ci;
    si--;

    if (s[si] == -1) {
      s[si] = ci;
    } else {
      if (s[si] != ci) die(-1);
    }
  }

  // first digit
  if (n == 1) {
    if (s[0] == -1) s[0] = 0;
  } else {
    if (s[0] == 0) die(-1);  // 0 is not allowed
    if (s[0] == -1) s[0] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if (s[i] == -1) s[i] = 0;
  }

  rep(i, n) cout << s[i];
  cout << endl;
}
