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

struct P {
  double x;
  double y;
};

int main() {
  int n;
  cin >> n;

  vector<P> dots;
  rep(_, n) {
    double x, y;
    cin >> x >> y;
    dots.push_back(P{x, y});
  }

  int cnt{};

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        auto a = dots[i];
        auto b = dots[j];
        auto c = dots[k];
        if (a.x == b.x || b.x == c.x || c.x == a.x) {
          if (!(a.x == b.x && b.x == c.x && c.x == a.x)) {
            cnt++;
          }
        } else {
          double grad1 = (a.y - b.y) / (a.x - b.x);
          double grad2 = (b.y - c.y) / (b.x - c.x);

          if (grad1 != grad2) {
            cnt++;
          }
        }
      }
    }
  }

  cout << cnt << el;
}
