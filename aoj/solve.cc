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
  int n;
  cin >> n;
  set<int> st;
  rep(i, n) {
    int a;
    cin >> a;
    st.insert(a);
  }

  int m;
  cin >> m;

  bool is_ok{true};
  rep(i, m) {
    int b;
    cin >> b;
    if (st.find(b) == st.end()) {
      is_ok = false;
    }
  }

  if (is_ok)
    output(1);
  else
    output(0);
}
