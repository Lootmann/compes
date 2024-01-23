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
  int n, k;
  cin >> n >> k;

  vector<int> ai(n);
  int min_num{100001};
  rep(i, n) {
    cin >> ai[i];
    chmin(min_num, ai[i]);
  }

  int min_cnt{};
  rep(i, n) {
    if (ai[i] == min_num) {
      min_cnt++;
    }
  }

  int rest_num = n - min_cnt;
  dump(n, min_cnt, rest_num);

  output((rest_num + k - 2) / (k - 1));
}
