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

void solve() {
  string equation;
  cin >> equation;

  vector<int> nums;
  for (auto ch : equation) {
    if ('0' <= ch && ch <= '9') {
      nums.push_back(ch - '0');
    }
  }

  sort(nums.begin(), nums.end());

  int len = (int)nums.size();
  rep(i, len) {
    cout << nums[i] << (i == len - 1 ? '\n' : '+');
  }
}

int main() {
  FastIO;
  int t{1};
  while (t--) solve();
}
