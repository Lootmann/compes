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

bool is_prime(int n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  if (n == 3) return true;
  if (n % 3 == 0) return false;

  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  FastIO;
  int num{2}, cnt{};

  vector<int> primes;
  while (cnt < 10001) {
    if (is_prime(num)) {
      cnt++;
      primes.push_back(num);
    }
    num++;
  }

  dump(primes.size());
  output(primes.back());
}
