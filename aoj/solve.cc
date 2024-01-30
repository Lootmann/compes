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

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> ai(n + 1, 0);
  rep(i, n) cin >> ai[i + 1];

  dump(ai);

  for (int i = 1; i <= n; ++i) {
    cout << "node " << i << ": ";
    cout << "key = " << ai[i] << ", ";

    if (1 <= i / 2) {
      cout << "parent key = " << ai[i / 2] << ", ";
    }

    if (1 <= 2 * i && 2 * i <= n) {
      cout << "left key = " << ai[2 * i] << ", ";
    }

    if (1 <= 2 * i + 1 && 2 * i + 1 <= n) {
      cout << "right key = " << ai[2 * i + 1] << ", ";
    }
    cout << '\n';
  }
}
