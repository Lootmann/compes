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

set<int> gen_divisors(int n) {
  set<int> res{1, n};
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res.insert(i);
      res.insert(n / i);
    }
  }
  return res;
}
int main() {
  FastIO;
  int a, b;
  cin >> a >> b;

  set<int> divisors = gen_divisors(a);
  dump(divisors);

  int cnt{};
  for (auto div : divisors) {
    if (div % b == 0) {
      cnt++;
    }
  }
  output(cnt);
}
