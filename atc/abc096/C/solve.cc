#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;
  int H, W;
  cin >> H >> W;

  vector<string> cambus;
  rep(h, H) {
    string line;
    cin >> line;
    cambus.push_back(line);
  }

  vector<vector<char>> paint_area(H, vector<char>(W, '.'));
  rep(h, H) {
    rep(w, W) {
      // vertical
      if (w < W - 1) {
        if (cambus[h][w] == '#' && cambus[h][w + 1] == '#') {
          paint_area[h][w] = '#';
          paint_area[h][w + 1] = '#';
        }
      }

      // horizontal
      if (h < H - 1) {
        if (cambus[h][w] == '#' && cambus[h + 1][w] == '#') {
          paint_area[h][w] = '#';
          paint_area[h + 1][w] = '#';
        }
      }
    }
  }

  bool is_same{true};
  rep(h, H) dump(cambus[h]);
  rep(h, H) dump(paint_area[h]);

  rep(h, H) {
    rep(w, W) {
      if (cambus[h][w] != paint_area[h][w]) {
        is_same = false;
      }
    }

    if (!is_same) {
      die("No");
    }
  }

  output("Yes");
}
