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
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];
  vector<bool> flags(4, false);
  bool is_inc{true}, is_mono_inc{true};
  bool is_dec{true}, is_mono_dec{true};

  rep(i, n - 1) {
    if (ai[i] < ai[i + 1]) {
      is_dec = false;
      is_mono_dec = false;
    } else if (ai[i] <= ai[i + 1]) {
      is_mono_dec = false;
      is_mono_inc = false;
    } else if (ai[i] > ai[i + 1]) {
      is_inc = false;
      is_mono_inc = false;
    } else if (ai[i] >= ai[i + 1]) {
      is_mono_dec = false;
      is_mono_inc = false;
    }
  }

  dump(is_mono_inc, is_inc, is_mono_dec, is_dec);

  if (is_mono_inc) {
    output(2);
  } else if (is_mono_dec) {
    output(-2);
  } else if (is_inc && is_dec) {
    output(0);
  } else if (is_inc) {
    output(1);
  } else {
    output(-1);
  }
}
