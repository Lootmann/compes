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
  int k;
  cin >> k;

  vector<int> prime_die{2, 3, 5, 7, 11, 13};
  vector<int> comp_die{4, 6, 8, 9, 10, 12};

  int cnt{};
  rep(i, 6) rep(j, 6) {
    if (prime_die[i] * comp_die[j] == k) {
      cnt++;
    }
  }

  cout << fixed << setprecision(19);
  output(double(cnt) / 36);
}
