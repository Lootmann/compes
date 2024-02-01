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
vector<llint> memo(10, 0);

bool is_curious_number(int num) {
  llint sum{};
  int tmp = num;
  while (tmp > 0) {
    int idx = tmp % 10;
    tmp /= 10;
    sum += memo[idx];
  }
  return sum == num;
}

int main() {
  FastIO;

  memo[0] = 1;
  for (int i = 0; i < 9; ++i) {
    memo[i + 1] = memo[i] * (i + 1);
  }

  dump(memo);

  llint sum{};
  for (int i = 3; i <= 9999999; ++i) {
    if (is_curious_number(i)) {
      dump(i);
      sum += i;
    }
  }
  output(sum);
}
