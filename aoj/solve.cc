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
#define INTi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

bool can_div_3(int n) {
  return n % 3 == 0;
}

bool has_digit_3(int n) {
  bool is_ok{false};
  for (auto ch : to_string(n)) {
    if (ch == '3') is_ok = true;
  }
  return is_ok;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  for (int i = 3; i <= n; ++i) {
    if (can_div_3(i) || has_digit_3(i)) {
      cout << ' ' << i;
    }
  }
  cout << '\n';
}
