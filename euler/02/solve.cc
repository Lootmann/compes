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

  vector<llint> fib(50, 0);
  fib[0] = 1;
  fib[1] = 2;
  for (int i = 2; i < 50; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  llint limit{400'0000};
  llint sum{};

  int idx{0};
  while (fib[idx] < limit) {
    if (fib[idx] % 2 == 0) {
      sum += fib[idx];
    }
    idx++;
  }

  dump(sum);
  output(sum);
}
