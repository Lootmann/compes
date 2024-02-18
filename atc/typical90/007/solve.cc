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

int lower_bound(const vector<llint>& rating, const llint student_rate) {
  int left = -1, right = (int)rating.size() - 1;

  while (right - left > 1) {
    int mid = left + (right - left) / 2;

    if (rating[mid] >= student_rate) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return left + 1;
}

int main() {
  int n;
  cin >> n;

  vector<llint> rating(n);
  rep(i, n) cin >> rating[i];

  sort(all(rating));

  int q;
  cin >> q;

  rep(_, q) {
    llint b;
    cin >> b;

    // lower bound
    int idx = lower_bound(rating, b);
    llint cur{INFll};

    if (0 < idx) {
      chmin(cur, abs(b - rating[idx - 1]));
    }

    if (idx < n) {
      chmin(cur, abs(b - rating[idx]));
    }

    cout << cur << el;
  }
}
