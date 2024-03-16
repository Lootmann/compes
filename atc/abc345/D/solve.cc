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
using VVB = vector<vector<bool>>;
using VB = vector<bool>;
using VP = vector<P>;

int N, H, W;

bool can_fill(VP rots) {
  int n = (int)rots.size();

  VVB tiles(H, VB(W, false));
  rep(i, n) {
    int hh = rots[i].first;
    int ww = rots[i].second;

    rep(h, H - hh + 1) rep(w, W - ww + 1) {
      // check empty tiles
      bool can_place{true};
      rep(i, hh) rep(j, ww) {
        if (tiles[h + i][w + j]) {
          can_place = false;
        }
      }

      // when can_place is true, fill tiles
      if (can_place) {
        rep(i, hh) rep(j, ww) {
          tiles[h + i][w + j] = true;
        }
        break;
      }
    }
  }

  // tiles fill?
  bool is_filled{true};
  rep(h, H) rep(w, W) {
    if (!tiles[h][w]) is_filled = false;
  }

  return is_filled;
}

void searching(VP cells) {
  sort(all(cells));
  int n = (int)cells.size();

  do {
    VP rots = cells;

    for (int bit = 0; bit < (1 << n); ++bit) {
      for (int i = 0; i < n; ++i) {
        // rotation a cell
        if (bit & (1 << i)) {
          int k = rots[i].first;
          rots[i].first = rots[i].second;
          rots[i].second = k;
        }
      }

      if (can_fill(rots)) die("Yes");
    }
  } while (next_permutation(all(cells)));
}

int main() {
  cin >> N >> H >> W;

  VP cells;
  rep(_, N) {
    int a, b;
    cin >> a >> b;
    cells.push_back({a, b});
  }

  for (int bit = 0; bit < (1 << N); ++bit) {
    VP used;
    for (int i = 0; i < N; ++i) {
      if (bit & (1 << i)) {
        used.push_back(cells[i]);
      }
    }
    searching(used);
  }
  cout << "No" << el;
}
