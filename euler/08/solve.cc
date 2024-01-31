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

string get_lines() {
  string res{}, l{};
  while (cin >> l) res += l;
  return res;
}

int main() {
  FastIO;
  string digits = get_lines();

  llint ans{};
  int n = (int)digits.size();

  rep(i, n - 12) {
    llint sum{1};
    rep(k, 13) sum *= (int)(digits[i + k] - '0');

    chmax(ans, sum);
  }

  output(ans);
}
