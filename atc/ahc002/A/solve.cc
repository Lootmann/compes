#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
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
using VVI = vector<vector<int>>;

int dy[]{0, 1, -1, 0};
int dx[]{-1, 0, 0, 1};
string move_str = "LDUR";

struct Pos {
  int y;
  int x;
  Pos(int yy, int xx) : y(yy), x(xx) {}
};

bool is_inbound(int y, int x) {
  return 0 <= y && y < 50 && 0 <= x && x < 50;
}

void solve(const int si, const int sj, VVI& ti, const VVI& pi) {
  int y = si, x = sj;
  int point = pi[y][x];

  vector<bool> visited(50 * 50, false);
  visited[ti[y][x]] = true;

  string ans{};

  while (true) {
    int next_move = -1;
    int next_point = point;

    rep(k, 4) {
      int ny = y + dy[k];
      int nx = x + dx[k];

      if (!is_inbound(ny, nx)) continue;
      if (visited[ti[ny][nx]]) continue;
      if (next_point > point + pi[ny][nx]) continue;

      if (chmax(next_point, point + pi[ny][nx])) {
        next_move = k;
      }
    }

    if (next_move == -1) break;
    y = y + dy[next_move];
    x = x + dx[next_move];

    visited[ti[y][x]] = true;
    point += pi[y][x];
    ans += move_str[next_move];
  }

  cout << ans << '\n';
}

int main() {
  FastIO;
  int y, x;
  cin >> y >> x;
  VVI ti(50, vector<int>(50)), pi(50, vector<int>(50));
  rep(i, 50) rep(j, 50) cin >> ti[i][j];
  rep(i, 50) rep(j, 50) cin >> pi[i][j];
  solve(y, x, ti, pi);
}
