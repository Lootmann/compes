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
using P = pair<string, int>;

int main() {
  FastIO;

  int n, q;
  cin >> n >> q;
  queue<P> que;

  rep(_, n) {
    string s;
    int time;
    cin >> s >> time;
    que.push(make_pair(s, time));
  }

  int total{};
  while (!que.empty()) {
    auto now = que.front();
    que.pop();

    // consume
    if (now.second <= q) {
      total += now.second;
      cout << now.first << ' ' << total << '\n';
    } else {
      total += q;
      now.second -= q;
      que.push(now);
    }
  }
}
