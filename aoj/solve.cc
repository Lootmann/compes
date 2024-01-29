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

namespace me {
llint gcd(llint a, llint b) {
  if (b == 0) return a;
  if (a > b)
    return gcd(b, a % b);
  else
    return gcd(a, b % a);
}

llint lcm(llint a, llint b) {
  return a / gcd(a, b) * b;
}
}  // namespace me

int main() {
  FastIO;
  llint a, b;
  while (cin >> a >> b) {
    cout << gcd(a, b) << ' ' << lcm(a, b) << '\n';
  }
}
