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
  int n;
  cin >> n;

  deque<int> que;

  // 10^5
  rep(i, n) {
    int a;
    cin >> a;

    if (i % 2 == 0) {
      // logN ?
      que.push_front(a);
    } else {
      que.push_back(a);
    }
  }

  // pop back
  if (n % 2 == 0) {
    rep(i, n) {
      cout << que.back();
      que.pop_back();
      cout << (i == n - 1 ? '\n' : ' ');
    }
  } else {
    // pop front
    rep(i, n) {
      cout << que.front();
      que.pop_front();
      cout << (i == n - 1 ? '\n' : ' ');
    }
  }
}
