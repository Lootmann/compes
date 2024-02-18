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

struct Piece {
  llint h;
  llint w;
};

int main() {
  llint h, w, n;
  cin >> h >> w >> n;

  vector<llint> ai(n);
  rep(i, n) cin >> ai[i];

  vector<llint> sides(n);
  llint total_area{};
  rep(i, n) {
    sides[i] = pow(2, ai[i]);
    total_area = sides[i] * sides[i];
  }
  sort(rall(sides));

  // ton of piece
  if (total_area > h * w) die("No");

  // simulation
  vector<Piece> ps;
  ps.push_back(Piece{h, w});

  rep(i, n) {
    llint k = sides[i];

    // どれか一つでも分割できればOK
    bool can_divide{false};
    for (auto p : ps) {
      if (min(p.h, p.w) >= k) {
        can_divide = true;
      }
    }

    if (!can_divide) die("No");

    // split
    //
    //   k   w - k
    // +---+-----+
    // |   |     | k
    // +---+.....|
    // |   .     | h - k
    // |   .     |
    // +---------+
    //  k    w - k
    rep(j, (int)ps.size()) {
      auto p = ps[j];
      if (min(p.h, p.w) >= k) {
        ps.erase(ps.begin() + j);

        // split piece
        llint h_k = p.h - k;
        llint w_k = p.w - k;
        ps.push_back({h_k, k});
        ps.push_back({k, w_k});
        ps.push_back({h_k, w_k});
        break;
      }
    }  // rep

  }  // all process

  out("Yes");
}
