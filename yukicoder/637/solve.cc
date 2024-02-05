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

int fizzbuzz(int n) {
  if (n % 15 == 0) return 8;
  if (n % 3 == 0 || n % 5 == 0) return 4;

  int cnt{};
  while (n > 0) {
    cnt++;
    n /= 10;
  }
  return cnt;
}

int main() {
  FastIO;

  vector<int> vi(5);
  rep(i, 5) cin >> vi[i];

  int sum{};
  rep(i, 5) {
    sum += fizzbuzz(vi[i]);
  }
  output(sum);
}
