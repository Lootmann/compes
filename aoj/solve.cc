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

bool is_triangle(int a, int b, int c) {
  bool is_ok{false};
  is_ok |= (c * c == a * a + b * b);
  is_ok |= (a * a == b * b + c * c);
  is_ok |= (b * b == c * c + a * a);
  return is_ok;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  rep(_, n) {
    int a, b, c;
    cin >> a >> b >> c;

    if (is_triangle(a, b, c)) {
      output("YES");
    } else {
      output("NO");
    }
  }
}
