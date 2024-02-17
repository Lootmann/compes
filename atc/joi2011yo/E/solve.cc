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
#define el '\n'

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

int dh[]{-1, 0, 0, 1};
int dw[]{0, 1, -1, 0};

bool compare(const pair<char, P>& a, const pair<char, P>& b) {
  return a.first < b.first;
}

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  auto bfs = [&](int start_h, int start_w, char goal) -> int {
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector dist(H, vector<int>(W, 0));
    queue<P> que;

    visited[start_h][start_w] = true;
    que.push({start_h, start_w});

    while (!que.empty()) {
      auto [h, w] = que.front();
      que.pop();

      rep(k, 4) {
        int nh = h + dh[k];
        int nw = w + dw[k];

        if (!(0 <= nh && nh < H && 0 <= nw && nw < W)) continue;
        if (grid[nh][nw] == 'X') continue;
        if (visited[nh][nw]) continue;
        if (grid[nh][nw] == goal) return dist[h][w] + 1;

        dist[nh][nw] = dist[h][w] + 1;
        visited[nh][nw] = true;
        que.push({nh, nw});
      }
    }

    return 99999999;
  };

  // find goal char and position
  // S -> 1 -> 2 -> 3 ->  ...
  vector<pair<char, P>> goals;
  rep(h, H) rep(w, W) {
    char ch = grid[h][w];
    if ('1' <= ch && ch <= '9') {
      goals.push_back({ch, {h, w}});
    }
  }
  // need sort '1' -> '2' -> '3'
  // can use set<> instead of 'goals'
  sort(all(goals), compare);

  // found start pos
  int sh{}, sw{};
  rep(i, H) rep(j, W) {
    if (grid[i][j] == 'S') {
      sh = i, sw = j;
    }
  }

  // dfs
  int ans{};

  for (auto [goal_char, Pos] : goals) {
    ans += bfs(sh, sw, goal_char);
    sh = Pos.first;
    sw = Pos.second;
  }

  out(ans);
}
