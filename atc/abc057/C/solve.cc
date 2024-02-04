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

llint F(llint a, llint b) {
  int cnt1{};
  while (a > 0) {
    a /= 10;
    cnt1++;
  }

  int cnt2{};
  while (b > 0) {
    b /= 10;
    cnt2++;
  }

  return max(cnt1, cnt2);
}

int main() {
  FastIO;
  llint N;
  cin >> N;

  llint ans{100};
  for (llint i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      llint a = i;
      llint b = N / i;
      chmin(ans, F(a, b));
    }
  }
  output(ans);
}
