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

// define directions
#define NORTH 0
#define WEST 1
#define SOUTH 2
#define EAST 3

struct Pos {
  int x;
  int y;
  int d;  // direction

  void _move(int _d, int& _x, int& _y) {
    switch (_d) {
      case NORTH:
        _y--;
        break;
      case WEST:
        _x--;
        break;
      case SOUTH:
        _y++;
        break;
      case EAST:
        _x++;
        break;
    }
  }

  void move() { _move(d, x, y); }

  void changeDirection() {
    // north -> west -> south -> east
    d = (d + 1) % 4;
  }

  tuple<int, int> next_move() {
    int xx = x, yy = y;
    _move(d, xx, yy);
    return tuple(xx, yy);
  }
};

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n, 0));
  Pos p;
  if (n % 2 == 0) {
    p.x = 0, p.y = n - 1;
    p.d = EAST;
  } else {
    p.x = n - 1, p.y = 0;
    p.d = WEST;
  }

  int cnt{n * n + 1};

  while (--cnt) {
    auto [x, y] = p.next_move();

    // check outbound
    if (!(0 <= x && x < n && 0 <= y && y < n)) {
      p.changeDirection();
    } else {
      // inbound but next move's cell is filled some number,
      // except 0 ...
      if (grid[y][x] != 0) {
        p.changeDirection();
      }
    }

    // go move
    grid[p.y][p.x] = cnt;
    p.move();
  }

  // calc spiral sum
  int sum{};
  rep(i, n) sum += grid[i][i];
  rep(i, n) sum += grid[n - i - 1][i];
  sum -= grid[n / 2][n / 2];
  dump(n, sum);
  output(sum);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
