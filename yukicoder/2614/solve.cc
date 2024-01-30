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

// ABAC        BC 6
// ABAC ABC    BC 9
// ABAC ABCABC BC 12
int main() {
  FastIO;
  int t;
  cin >> t;

  rep(_, t) {
    int n;
    cin >> n;
    dump(n);

    string res{"ABAC"};
    rep(__, n - 2) {
      res += "ABC";
    }
    res += "BC";
    output(res);
  }
}
