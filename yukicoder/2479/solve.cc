#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

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

using llint = long long int;

int main() {
  FastIO;
  llint s;
  cin >> s;

  vector<llint> ans;
  for (llint i = sqrt(s); i >= 1; --i) {
    while (s >= i * i) {
      s -= i * i;
      ans.push_back(i * i);
    }

    if (s == i * i) {
      ans.push_back(i * i);
      break;
    }
  }

  int n = (int)ans.size();
  out(n);
  rep(i, n) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}
