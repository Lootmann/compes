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
bool binary_search(const vector<int>& ai, int k) {
  int left = 0, right = (int)ai.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (ai[mid] == k) {
      return true;
    } else if (k < ai[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return false;
}
}  // namespace me

int main() {
  FastIO;
  int n;
  cin >> n;
  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  int cnt{};
  int q;
  cin >> q;

  rep(_, q) {
    int t;
    cin >> t;
    if (me::binary_search(ai, t)) {
      cnt++;
    }
  }
  output(cnt);
}
