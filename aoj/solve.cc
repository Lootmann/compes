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
  deque<int> que;

  int n;
  cin >> n;

  rep(_, n) {
    int op;
    cin >> op;

    if (op == 0) {
      int d, x;
      cin >> d >> x;
      if (d == 0)
        que.push_front(x);
      else
        que.push_back(x);

    } else if (op == 1) {
      int p;
      cin >> p;
      output(que[p]);

    } else {
      int d;
      cin >> d;
      if (d == 0)
        que.pop_front();
      else
        que.pop_back();
    }
  }
}
