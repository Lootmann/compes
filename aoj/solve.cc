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
  FastIO;
  int n, k;
  cin >> n >> k;
  k--;

  string t;
  cin >> t;

  for (int i = 0; i < k; ++i) {
    cout << t[i];
  }

  for (int i = k; i < n; ++i) {
    if ('a' <= t[i] && t[i] <= 'z') {
      cout << (char)(t[i] - 'a' + 'A');
    } else {
      cout << (char)(t[i] - 'A' + 'a');
    }
  }
  cout << '\n';
}
