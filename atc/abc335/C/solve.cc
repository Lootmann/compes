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
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;

  // init (x, y)
  deque<P> que;
  rep(x, n) que.push_back({x + 1, 0});

  int x{1}, y{0};
  rep(_, q) {
    int t;
    cin >> t;

    if (t == 1) {
      char c;
      cin >> c;

      if (c == 'U')
        y++;
      else if (c == 'D')
        y--;
      else if (c == 'R')
        x++;
      else
        x--;

      // push
      que.push_front({x, y});
      while ((int)que.size() > n) {
        que.pop_back();
      }
    } else {
      int p;
      cin >> p;

      auto [nx, ny] = que[p - 1];
      cout << nx << ' ' << ny << '\n';
    }
  }
}
