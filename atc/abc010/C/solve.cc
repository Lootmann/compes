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
  long double Txa, Tya, Txb, Tyb, T, V;
  cin >> Txa >> Tya >> Txb >> Tyb >> T >> V;

  bool can_visit{false};

  int n;
  cin >> n;
  rep(_, n) {
    long double x1, y1;
    cin >> x1 >> y1;

    long double dist{};
    dist += sqrtl(powl(Txa - x1, 2) + powl(Tya - y1, 2));
    dist += sqrtl(powl(x1 - Txb, 2) + powl(y1 - Tyb, 2));

    if (dist <= T * V) {
      can_visit = true;
    }
  }

  out(can_visit ? "YES" : "NO");
}
