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

int rpc(char a, char b) {
  // draw
  if (a == b) return 0;

  // winner a
  if (a == 'G' && b == 'C') return 1;
  if (a == 'C' && b == 'P') return 1;
  if (a == 'P' && b == 'G') return 1;

  // winner b
  return -1;
}

struct P {
  int score;
  int id;
};

bool compare(const P& a, const P& b) {
  if (a.score > b.score) return true;
  if (a.score < b.score) return false;
  return a.id < b.id;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> sheet(2 * n);
  rep(i, 2 * n) cin >> sheet[i];

  // score, id
  vector<P> parts;
  rep(i, 2 * n) {
    parts.push_back(P{0, i});
  }

  rep(j, m) {
    rep(i, n) {
      char a = sheet[parts[2 * i].id][j];
      char b = sheet[parts[2 * i + 1].id][j];

      if (rpc(a, b) == 1) {
        parts[2 * i].score++;
      } else if (rpc(a, b) == -1) {
        parts[2 * i + 1].score++;
      }
    }

    sort(all(parts), compare);
  }

  rep(i, 2 * n) {
    out(parts[i].id + 1);
  }
}
