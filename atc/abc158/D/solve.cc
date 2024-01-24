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
  string s;
  cin >> s;

  deque<char> que;

  for (auto ch : s) {
    que.push_back(ch);
  }

  bool is_flip{false};
  int q;
  cin >> q;

  rep(_, q) {
    int t;
    cin >> t;

    if (t == 1) {
      is_flip = !is_flip;
    } else {
      int f;
      char c;
      cin >> f >> c;

      if (f == 1) {
        if (is_flip)
          que.push_back(c);
        else
          que.push_front(c);
      } else {
        if (is_flip)
          que.push_front(c);
        else
          que.push_back(c);
      }
    }
  }

  while (!que.empty()) {
    if (is_flip) {
      cout << que.back();
      que.pop_back();

    } else {
      cout << que.front();
      que.pop_front();
    }
  }
  cout << '\n';
}
