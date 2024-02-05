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

string padding(int t) {
  if (t < 10) return "0" + to_string(t);
  return to_string(t);
}

int main() {
  FastIO;
  int a;
  cin >> a;
  int usage = a / 10 * 6;
  int now = 10 * 60 + usage;

  int hh = now / 60;
  now %= 60;
  int mm = now;
  cout << padding(hh) << ":" << padding(mm) << endl;
}
