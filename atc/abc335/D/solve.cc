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

int dy[]{0, -1, 0, 1};
int dx[]{1, 0, -1, 0};

int main() {
  int n;
  cin >> n;

  vector<vector<string>> grid(n, vector<string>(n, "."));

  int y{}, x{};
  int d{0};  // direction

  int mv{1};

  while (mv != n * n) {
    int ny = y + dy[d];
    int nx = x + dx[d];

    // outbound -> change direction
    if (!(0 <= ny && ny < n && 0 <= nx && nx < n)) {
      d = (d + 1) % 4;
      continue;
    }

    // grid has next
    if (grid[ny][nx] != ".") {
      d = (d + 1) % 4;
      continue;
    }

    grid[y][x] = to_string(mv++);
    y = ny, x = nx;

    if (mv == n * n) {
      grid[y][x] = "T";
    }
  }

  rep(h, n) {
    rep(w, n) {
      cout << grid[h][w] << (w == n - 1 ? '\n' : ' ');
    }
  }
}
