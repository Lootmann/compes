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

  string dango;
  cin >> dango;

  int ans{}, cnt{};
  for (int i = 0; i < n; ++i) {
    if (dango[i] == '-') {
      chmax(ans, cnt);
      cnt = 0;
    } else {
      cnt++;
    }
    dump(cnt);
  }

  cnt = 0;

  for (int i = n - 1; i >= 0; --i) {
    if (dango[i] == '-') {
      chmax(ans, cnt);
      cnt = 0;
    } else {
      cnt++;
    }

    dump(cnt);
  }

  if (ans == 0) {
    output(-1);
  } else {
    output(ans);
  }
}
