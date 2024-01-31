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

bool is_abundant(int n) {
  int sum{1};
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      sum += i;
      if (n / i != i) sum += n / i;
    }
  }

  return sum > n;
}

int main() {
  FastIO;

  vector<int> abundant;
  for (int i = 12; i <= 28123; ++i) {
    if (is_abundant(i)) {
      abundant.push_back(i);
    }
  }

  dump(abundant.size());

  set<int> all_sum;
  int n = (int)abundant.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      all_sum.insert(abundant[i] + abundant[j]);
    }
  }

  dump(all_sum.size());

  int sum{};
  rep(i, n * 3) {
    if (not all_sum.contains(i)) {
      sum += i;
    }
  }
  dump(all_sum.size());
  output(sum);
}
