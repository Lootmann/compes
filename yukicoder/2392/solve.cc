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

vector<int> pow_divisors(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; ++i) {
    res.push_back(i * i);
  }
  return res;
}

int main() {
  FastIO;
  int p;
  cin >> p;

  vector<int> divs = pow_divisors(p);
  int n = (int)divs.size();

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (divs[i] + divs[j] == p) {
        die("Yes");
      }
    }
  }
  out("No");
}
