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

llint collatz(llint n) {
  return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

llint solve(llint n) {
  llint cnt{};

  while (true) {
    cnt++;
    if (n == 1) break;
    n = collatz(n);
  }

  return cnt;
}

int main() {
  FastIO;

  llint cnt{};
  for (llint i = 1; i <= 100'0000; ++i) {
    if (chmax(cnt, solve(i))) {
      dump(i, cnt);
    }
  }
  output(cnt);
}
