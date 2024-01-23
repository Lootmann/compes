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
  set<int> st;

  while (true) {
    // cout << "tak" << endl;
    for (int i = 1; i <= 2 * n + 1; ++i) {
      if (!st.contains(i)) {
        cout << i << endl;
        st.insert(i);
        break;
      }
    }

    // cout << "aoki" << endl;
    int input{};
    cin >> input;

    if (input == 0) break;
    st.insert(input);
  }
  return 0;
}
