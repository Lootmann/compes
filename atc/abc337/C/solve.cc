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
  int n;
  cin >> n;

  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;

    if (a == -1)
      mp[0] = i + 1;
    else
      mp[a] = i + 1;
  }

  dump(mp);

  int cnt{n}, idx{0};
  while (cnt--) {
    idx = mp[idx];
    if (cnt == 0)
      cout << idx << '\n';
    else
      cout << idx << ' ';
  }
}
