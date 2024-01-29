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

  int total{};

  while (true) {
    // 1
    total++;
    int nd = n;

    // 2
    if (nd == 1) {
      total++;
      break;
    }

    // 3
    if (n % 2 == 0) {
      n = n / 2;
    } else {  // 4
      n = 3 * n + 1;
    }

    total++;

    if (total > 50) break;
  }

  if (total > 50) {
    output("No");
  } else {
    output("Yes");
    output(total);
  }
}
