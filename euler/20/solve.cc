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

void multiply(vector<int>& vi, int mul) {
  int carryup{0};

  rep(i, (int)vi.size()) {
    int res = carryup + vi[i] * mul;
    vi[i] = res % 10;
    carryup = res / 10;
  }

  while (carryup != 0) {
    vi.push_back(carryup % 10);
    carryup /= 10;
  }
}

void solve() {
  int n;
  cin >> n;

  vector<int> digits;
  digits.push_back(1);

  for (int i = 1; i <= n; ++i) {
    multiply(digits, i);
  }

  dump(digits);

  int sum{};
  for (auto num : digits) {
    sum += num;
  }
  output(sum);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
