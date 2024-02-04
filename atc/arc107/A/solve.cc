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

const llint MOD = 998244353;

llint mod(llint num) {
  return num % MOD;
}

int main() {
  FastIO;

  llint a, b, c;
  cin >> a >> b >> c;

  llint sumA = mod(a * (a + 1) / 2);
  llint sumB = mod(b * (b + 1) / 2);
  llint sumC = mod(c * (c + 1) / 2);

  output(mod(mod(sumA * sumB) * sumC));
}
