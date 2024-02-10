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

struct P {
  int x;
  int y;
};

int main() {
  int n;
  cin >> n;

  vector<P> pos;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    pos.push_back(P(x, y));
  }

  int cnt{};
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        auto [x1, y1] = pos[i];
        auto [x2, y2] = pos[j];
        auto [x3, y3] = pos[k];

        int grad1 = (y2 - y1) * (x3 - x2);
        int grad2 = (y3 - y2) * (x2 - x1);
        if (grad1 == grad2) {
          cnt++;
        }
      }
    }
  }

  if (cnt > 0)
    out("Yes");
  else
    out("No");
}
