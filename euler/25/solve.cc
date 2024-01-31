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
using VI = vector<int>;

void adding(VI& f1, VI& f2, VI& f3) {
  int carryup{};

  rep(i, 1000) {
    int sum = f1[i] + f2[i] + carryup;
    f3[i] = sum % 10;
    carryup = sum / 10;
  }
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> fib1(1001, 0), fib2(1001, 0), fib3(1001, 0);
  fib1[0] = 1;
  fib2[0] = 1;
  fib3[0] = 2;

  for (int i = 2; i <= n; ++i) {
    rep(k, 1000) {
      fib1[k] = fib2[k];
      fib2[k] = fib3[k];
    }
    adding(fib1, fib2, fib3);
  }
  dump(fib3);
}
