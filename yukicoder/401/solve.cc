#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define repa(i, a, n) for (int i = a; (int)i < n; ++i)
#define rrep(i, n) for (int i = n; (int)i >= 0; --i)
#define rrepa(i, a, n) for (int i = a; (int)i >= n; --i)
#define EACH(x, a) for (auto& x : a)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)

template <class A> void read(vector<A>& v);
template <class A, size_t S> void read(array<A, S>& a);
template <class T> void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T> void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A> void read(vector<A>& x) {
  EACH(a, x) read(a);
}
template <class A, size_t S> void read(array<A, S>& x) {
  EACH(a, x) read(a);
}
template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

vector<vector<int>> gen_moves(int n) {
  vector<vector<int>> res;
  for (int i = n - 1; i > 1; i -= 2) {
    vector<int> nums{};
    rep(_, 4) nums.push_back(i);
    res.push_back(nums);
  }

  vector<int> ones{1};
  if (n % 2 == 0) {
    rep(_, 3) ones.push_back(1);
  }
  res.push_back(ones);
  return res;
}

struct Pos {
  int y;
  int x;

  //   N
  // W   E
  //   S
  int d;  // direction
  Pos() : y{0}, x{0}, d{1} {}
  void changeDirection() { d = (d + 1) % 4; }
  void move() { d == 0 ? y-- : d == 1 ? x++ : d == 2 ? y++ : x--; }
  void back() { d == 0 ? y++ : d == 1 ? x-- : d == 2 ? y-- : x++; }
};

string format(int n) {
  if (n < 10) return "00" + to_string(n);
  if (n < 100) return "0" + to_string(n);
  return to_string(n);
}

int main() {
  FastIO;
  int n;
  read(n);

  vector<vector<int>> cells(n, vector<int>(n, 0));
  vector<vector<int>> moves = gen_moves(n);
  Pos pos;
  int cnt{1};

  for (auto mv : moves) {
    rep(i, (int)mv.size()) {
      rep(j, mv[i]) {
        cells[pos.y][pos.x] = cnt++;
        pos.move();
      }

      if (i == (int)mv.size() - 1) {
        pos.back();
        pos.changeDirection();
        pos.move();
      } else {
        pos.changeDirection();
      }
    }
  }

  rep(y, n) {
    rep(x, n) {
      cout << format(cells[y][x]) << (x == n - 1 ? '\n' : ' ');
    }
  }
}
