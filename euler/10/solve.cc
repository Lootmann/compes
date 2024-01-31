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

vector<bool> create_eratosthenes(int n) {
  vector<bool> sheet(n + 1, true);

  sheet[0] = false;
  sheet[1] = false;

  for (int p = 2; p <= n; ++p) {
    if (!sheet[p]) continue;

    for (int q = p * 2; q <= n; q += p) {
      sheet[q] = false;
    }
  }

  return sheet;
}

int main() {
  FastIO;

  int n;
  cin >> n;
  vector<bool> isPrime = create_eratosthenes(n);

  llint ans{};
  rep(i, n) {
    if (isPrime[i]) {
      ans += i;
      cout << i << ' ' << ans << endl;
    }
  }
  output(ans);
}
