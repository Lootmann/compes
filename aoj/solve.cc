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

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  set<int> sa, sb;
  rep(_, n) {
    int a;
    cin >> a;
    sa.insert(a);
  }

  vector<int> ans;
  rep(_, m) {
    int b;
    cin >> b;
    sb.insert(b);
  }

  for (auto num : sa) {
    if (sb.find(num) != sb.end()) {
      ans.push_back(num);
    }
  }

  dump(ans);

  for (auto num : ans) {
    output(num);
  }
}
