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

int main() {
  int n, k;
  cin >> n >> k;

  //     43210
  // 000001010
  bitset<32> subset(0);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    subset.set(x);
  }

  for (int i = 0; i < (1 << n); ++i) {
    bitset<32> tmp(i);

    if ((int)(tmp | subset).count() == k) {
      cout << i << ":";
      rep(j, n) {
        if (tmp[j]) cout << ' ' << j;
      }
      cout << '\n';
    }
  }

  return 0;
}
