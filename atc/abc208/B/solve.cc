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

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

int main() {
  FastIO;
  llint p;
  cin >> p;

  vector<llint> ai;
  llint num{1};
  for (int i = 1; i <= 10; ++i) {
    num *= i;
    ai.push_back(num);
  }
  sort(ai.rbegin(), ai.rend());

  int cnt{};
  rep(i, 10) {
    cnt += p / ai[i];
    p %= ai[i];
  }

  output(cnt);
}
