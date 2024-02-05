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

int main() {
  FastIO;
  int h, n;
  cin >> h >> n;

  vector<int> hi(n - 1);
  rep(i, n - 1) cin >> hi[i];
  sort(hi.rbegin(), hi.rend());
  dump(hi);

  int ans{};
  if (h > hi[0]) {
    ans = 1;
  } else {
    rep(i, n - 1) {
      if (h < hi[i]) {
        ans = i + 2;
      }
    }
  }

  if (ans == 0) {
    ans = n;
  }

  cout << ans;
  if (ans % 10 == 1) {
    cout << "st";
  } else if (ans % 10 == 2) {
    cout << "nd";
  } else if (ans % 10 == 3) {
    cout << "rd";
  } else {
    cout << "th";
  }
  cout << endl;
}
