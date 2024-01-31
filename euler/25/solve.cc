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
using VVI = vector<vector<int>>;

void out(const VVI& vi, int size) {
  int idx{};
  for (int i = 1000; i >= 0; --i) {
    if (vi[size][i] != 0) {
      idx = i;
      break;
    }
  }

  cout << idx << " -> ";

  for (int i = idx; i >= 0; --i) {
    cout << vi[size][i];
  }
  cout << '\n';

  if (idx >= 999) exit(0);
}

void adding(VVI& fib, int n) {
  int carryup{0};

  rep(i, (int)fib[n - 2].size()) {
    int res = fib[n - 1][i] + fib[n - 2][i] + carryup;
    fib[n][i] = res % 10;
    carryup = res / 10;

    if (carryup >= 1) {
      fib[n][i + 1] = carryup;
    }
  }
}

int main() {
  FastIO;
  int n;
  cin >> n;

  VVI fib(n + 1, vector<int>(1020, 0));
  fib[0][0] = 1;
  fib[1][0] = 1;

  for (int i = 2; i <= n; ++i) {
    adding(fib, i);
    cout << "[" << i << "] =\n";
    out(fib, i);
  }
}
