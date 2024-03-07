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

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  bool is_swap{false};

  int q;
  cin >> q;
  rep(_, q) {
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;

    if (t == 1) {
      if (is_swap) {
        a = (n + a) % (2 * n);
        b = (n + b) % (2 * n);
      }
      swap(s[a], s[b]);
    } else {
      is_swap = !is_swap;
    }
  }

  if (is_swap) {
    cout << s.substr(n) << s.substr(0, n) << el;
  } else {
    cout << s << el;
  }
}
