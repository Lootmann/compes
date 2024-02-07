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

int main() {
  FastIO;
  string s;
  cin >> s;

  vector<int> ps;

  string yuki{"yukicoder"};
  auto pos = s.find(yuki);
  if (pos == string::npos) die(0);

  ps.push_back(pos);
  while (pos != string::npos) {
    pos = s.find(yuki, pos + yuki.size());
    if (pos != string::npos) ps.push_back(pos);
  }

  int ans{1};
  if (ps.size() == 1) die(ans);

  int cnt{};
  rep(i, (int)ps.size() - 1) {
    if (ps[i + 1] - ps[i] == 9) {
      if (cnt == 0) {
        cnt = 2;
      } else {
        cnt++;
      }
    } else {
      cnt = 0;
    }
    chmax(ans, cnt);
  }

  out(ans);
}
