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
  // 1 <= N <= 100
  int N, K;
  cin >> N >> K;

  vector<int> ws(N);
  rep(i, N) cin >> ws[i];

  int maxw{};
  rep(i, N) chmax(maxw, ws[i]);

  int left = maxw - 1;
  int right = 1e9 + 7;

  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    int num{1}, cur{0};
    rep(i, N) {
      if (cur + ws[i] > mid) {
        num++;
        cur = ws[i];
      } else {
        cur += ws[i];
      }
    }

    if (num <= K) {
      right = mid;
    } else {
      left = mid;
    }
  }

  output(right);
}
