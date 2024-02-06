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

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;
  vector<int> pi(2, 0);
  cin >> pi[0] >> pi[1];
  sort(pi.begin(), pi.end());

  int a = pi[0] - 4;
  int b = pi[1] + 4;

  if (0 <= a && a <= 11) die(a);
  if (0 <= b && b <= 11) die(b);
  output(pi[0] + 4);
}
