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

void solve() {
  int n;
  cin >> n;

  vector<int> wi(n);
  rep(i, n) cin >> wi[i];

  // cumulative sum
  vector<int> alice(n), bob(n);

  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      alice[0] = wi[0];
    } else {
      alice[i] = alice[i - 1] + wi[i];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      bob[i] = wi[i];
    } else {
      bob[i] = bob[i + 1] + wi[i];
    }
  }

  int ans{};
  int left{0}, right{n - 1};

  while (left < right) {
    if (alice[left] == bob[right]) {
      chmax(ans, (left + 1) + (n - right));
    }

    if (alice[left] <= bob[right]) {
      left++;
    } else if (alice[left] > bob[right]) {
      right--;
    }
  }

  out(ans);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
