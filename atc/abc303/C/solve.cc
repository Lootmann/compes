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

void make_move(int& y, int& x, char ch) {
  if (ch == 'U') {
    y++;
  } else if (ch == 'D') {
    y--;
  } else if (ch == 'R') {
    x++;
  } else {
    x--;
  }
}

int main() {
  int n, m, hp, k;
  cin >> n >> m >> hp >> k;

  string s;
  cin >> s;

  set<pair<int, int>> items;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    items.insert({y, x});
  }

  int y{}, x{};
  rep(i, n) {
    make_move(y, x, s[i]);
    hp--;
    if (hp < 0) break;

    if (hp < k) {
      // find items
      if (items.find({y, x}) != items.end()) {
        hp = k;
        items.erase({y, x});
      }
    }
  }

  if (hp >= 0)
    out("Yes");
  else
    out("No");
}
