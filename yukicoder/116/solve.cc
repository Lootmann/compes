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
  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  int cnt{};

  rep(i, n - 2) {
    int a = ai[i];
    int b = ai[i + 1];
    int c = ai[i + 2];
    if (a == b || b == c || c == a) continue;
    if ((b > a && a > c) || (b < a && a < c) || (a > c && c > b) ||
        (a < c && c < b)) {
      cnt++;
    }
  }
  output(cnt);
}
