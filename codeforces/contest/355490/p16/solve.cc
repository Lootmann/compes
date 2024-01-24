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

bool is_almost_primes(int n) {
  set<int> primes;

  for (int i = 2, nn = n; i * i <= nn; ++i) {
    while (n % i == 0) {
      primes.insert(i);
      n /= i;
    }
  }

  if (n != 1) {
    primes.insert(n);
  }

  return primes.size() == 2;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  int cnt{};
  for (int i = 1; i <= n; ++i) {
    if (is_almost_primes(i)) {
      cnt++;
    }
  }
  output(cnt);
}
