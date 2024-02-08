#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

using llint = long long int;

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

bool is_r(char ch) {
  return ch == 'R';
}

bool is_g_or_b(char ch) {
  return ch == 'G' || ch == 'B';
}

void solve() {
  int n;
  cin >> n;

  string top, bottom;
  cin >> top >> bottom;

  bool is_identical{true};

  rep(i, n) {
    char t = top[i], b = bottom[i];

    if (is_r(t) && !is_r(b)) {
      is_identical = false;
    }

    if (is_r(b) && !is_r(t)) {
      is_identical = false;
    }

    if (is_g_or_b(t) && !is_g_or_b(b)) {
      is_identical = false;
    }

    if (is_g_or_b(b) && !is_g_or_b(t)) {
      is_identical = false;
    }
  }

  if (is_identical)
    out("YES");
  else
    out("NO");
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
