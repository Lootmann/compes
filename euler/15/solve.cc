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

void prime_divisior(map<int, int>& mp, int k) {
  for (int i = 2; i * i <= k; ++i) {
    while (k % i == 0) {
      mp[i]++;
      k /= i;
    }
  }

  if (k != 1) {
    mp[k]++;
  }
}

int main() {
  FastIO;
  map<int, int> mp_n, mp_r;

  int n, r;
  cin >> n >> r;

  for (int k = 0; k < r; ++k) {
    prime_divisior(mp_n, n - k);
  }

  for (int k = r; k >= 1; --k) {
    prime_divisior(mp_r, k);
  }

  llint ans{1};

  for (auto key : mp_n) {
    rep(_, key.second - mp_r[key.first]) {
      ans *= key.first;
    }
  }

  output(ans);
}
