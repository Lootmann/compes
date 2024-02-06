#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

const llint MOD = 998244353;

llint modpow(llint x, llint n) {
  x = x % MOD;

  if (n == 0) {
    return 1;
  } else if (n % 2 == 1) {
    return (x * modpow(x, n - 1)) % MOD;
  } else
    return modpow((x * x) % MOD, n / 2) % MOD;
}

int main() {
  FastIO;
  llint a, n;
  cin >> a >> n;

  output(MOD);
  output(modpow(a, n));
}
