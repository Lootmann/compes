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
  llint s, p;
  cin >> s >> p;

  vector<llint> divs;
  for (llint i = 1; i * i <= p; ++i) {
    if (p % i == 0) {
      divs.push_back(i);
      divs.push_back(p / i);
    }
  }

  for (int i = 0; i < (int)divs.size() / 2; ++i) {
    llint n = divs[2 * i];
    llint m = divs[2 * i + 1];
    if (n + m == s) {
      die("Yes");
    }
  }

  output("No");
}
