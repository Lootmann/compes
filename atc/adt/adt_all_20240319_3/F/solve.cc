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
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
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

using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  map<int, int> left_move, right_move;
  vector<P> pos(n);
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    pos[i] = {x, y};

    // init
    chmax(left_move[y], x);
    chmin(right_move[y], -1);
  }

  string s;
  cin >> s;
  rep(i, n) {
    auto [x, y] = pos[i];

    if (s[i] == 'R') {
      chmin(left_move[y], x);
    } else {
      chmax(right_move[y], x);
    }
  }

  rep(i, n) {
    int y = pos[i].second;
    if (left_move[y] < right_move[y]) {
      die("Yes");
    }
  }

  cout << "No" << el;
}
