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
  int n;
  cin >> n;

  vector<int> judge(4, 0);
  rep(_, n) {
    string s;
    cin >> s;

    if (s == "AC") {
      judge[0]++;
    } else if (s == "WA") {
      judge[1]++;
    } else if (s == "TLE") {
      judge[2]++;
    } else {
      judge[3]++;
    }
  }

  cout << "AC x " << judge[0] << '\n';
  cout << "WA x " << judge[1] << '\n';
  cout << "TLE x " << judge[2] << '\n';
  cout << "RE x " << judge[3] << '\n';
}
