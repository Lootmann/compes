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

bool is_palidrome(int n) {
  int a = n / 100000;
  int b = n / 10000 % 10;
  int c = n / 1000 % 10;
  int d = n / 100 % 10;
  int e = n / 10 % 10;
  int f = n % 10;
  return a == f && b == e && c == d;
}

int main() {
  FastIO;

  int max_palidrome{0};

  // 9999 * 9999
  for (int i = 1; i <= 9999; ++i) {
    for (int j = 1; j <= 9999; ++j) {
      if (is_palidrome(i * j)) {
        chmax(max_palidrome, i * j);
      }
    }
  }

  output(max_palidrome);
}
