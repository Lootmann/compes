#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

#define WHITE '.'
#define BLACK '#'

void change_direction(int& d, int dd) {
  d = (d + dd) % 4;
}

int main() {
  FastIO;
  int H, W, N;
  cin >> H >> W >> N;

  vector<string> grid(H);
  rep(h, H) rep(w, W) grid[h] += '.';

  int direction{0};
  int h{0}, w{0};

  // up -> right -> down -> left
  auto move_grid = [&]() {
    if (direction == 0) h--;  // up
    if (direction == 1) w++;  // right
    if (direction == 2) h++;  // down
    if (direction == 3) w--;  // left

    // move on the torus
    if (h < 0)
      h = H - 1;
    else if (h >= H)
      h = 0;
    else if (w < 0)
      w = W - 1;
    else if (w >= W)
      w = 0;
  };

  rep(_, N) {
    if (grid[h][w] == WHITE) {
      grid[h][w] = BLACK;
      change_direction(direction, 1);
    } else {
      grid[h][w] = WHITE;
      change_direction(direction, 3);
    }
    move_grid();
  }

  rep(i, H) output(grid[i]);
}
