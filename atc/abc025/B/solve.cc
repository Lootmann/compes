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

int direction(const string& s, int a, int b, int d) {
  if (s == "West") {
    if (d < a)
      return a;
    else if (a <= d && d <= b)
      return d;
    else
      return b;
  } else {
    if (d < a)
      return -a;
    else if (a <= d && d <= b)
      return -d;
    else
      return -b;
  }
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  int pos{};

  rep(_, n) {
    string s;
    int d;
    cin >> s >> d;

    pos += direction(s, a, b, d);
    dump(s, pos);
  }

  if (pos > 0) {
    cout << "West " << pos;
  } else if (pos == 0) {
    cout << 0;
  } else {
    cout << "East " << -pos;
  }
  cout << '\n';
}
