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
using VVI = vector<vector<int>>;

int dy[]{0, 1, -1, 0};
int dx[]{-1, 0, 0, 1};

struct Pos {
  int y;
  int x;
  Pos(int yy, int xx) : y(yy), x(xx) {}
};

bool is_inbound(int y, int x) {
  return 0 <= y && y < 50 && 0 <= x && x < 50;
}

char move_direction(int y, int x) {
  if (y == -1 && x == 0) return 'U';
  if (y == 1 && x == 0) return 'D';
  if (y == 0 && x == -1) return 'L';
  if (y == 0 && x == 1) return 'R';
  throw runtime_error("move_direction :^)");
}

void solve(const int start_y, const int start_x, VVI& ti, const VVI& pi) {
  // 0 not visited
  vector<vector<int>> visited(50, vector<int>(50, 0));

  int id{1};
  visited[start_y][start_x] = id++;

  // check neighbor same tile
  rep(k, 4) {
    int ny = start_y + dy[k];
    int nx = start_x + dx[k];

    if (is_inbound(ny, nx)) {
      if (ti[start_y][start_x] == ti[ny][nx]) {
        visited[ny][nx] = -1;
      }
    }
  }

  // dfs
  stack<Pos> st;
  st.push(Pos(start_y, start_x));

  while (!st.empty()) {
    Pos cur = st.top();
    st.pop();

    rep(i, 4) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      // outbound
      if (!is_inbound(ny, nx)) continue;
      if (visited[ny][nx] != 0) continue;
      if (ti[cur.y][cur.x] == ti[ny][nx]) {
        visited[ny][nx] = -1;
        continue;
      }

      visited[ny][nx] = id++;

      st.push(Pos(ny, nx));
    }
  }

  // ans
  auto format = [](int n) {
    if (n < 0) return string("    ");
    if (n < 10) return "   " + to_string(n);
    if (n < 100) return "  " + to_string(n);
    if (n < 1000) return " " + to_string(n);
    return to_string(n);
  };

  rep(y, 50) {
    rep(x, 50) cout << format(visited[y][x]) << "|";
    cout << '\n';
    rep(x, 50) cout << "----+";
    cout << '\n';
  }
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
