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
#define INTi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;
const llint MOD = 998244353;

llint mod(const llint& n) {
  return n % MOD;
}

void memoization(vector<llint>& memo, llint n, llint a, llint b) {
  memo[0] = a;
  memo[1] = b;
  for (int i = 2; i <= n; ++i) {
    memo[i] = mod(mod(memo[i - 1]) + mod(memo[i - 2]) + MOD);
  }
}

int main() {
  FastIO;
  int q;
  cin >> q;

  vector<llint> rmemo(200010, 0), ememo(200010, 0);
  memoization(rmemo, 200005, 1, 1);
  memoization(ememo, 200005, 1, 3);

  rep(i, q) {
    llint n;
    cin >> n;
    n--;

    llint r = mod(mod(rmemo[n]) * mod(rmemo[n]));
    llint e = mod(mod(ememo[n]) * mod(ememo[n]));
    llint ans = mod(mod((mod(r) * 5) - mod(e)) + MOD);

    output(ans);
  }
}
