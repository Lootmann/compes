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

bool search(const vector<int>& si, int k) {
  for (auto num : si) {
    if (num == k) return true;
  }
  return false;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> si(n);
  rep(i, n) cin >> si[i];

  int q;
  cin >> q;

  int cnt{};
  rep(_, q) {
    int t;
    cin >> t;
    if (search(si, t)) {
      cnt++;
    }
  }
  output(cnt);
}
