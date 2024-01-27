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
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  set<int> st;
  // calc bit search
  for (int bit = 0; bit < (1 << n); ++bit) {
    int cnt{};
    rep(i, n) {
      if (bit & (1 << i)) {
        cnt += ai[i];
      }
    }
    st.insert(cnt);
  }

  int q;
  cin >> q;
  rep(_, q) {
    int m;
    cin >> m;

    if (st.find(m) != st.end()) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
    }
  }
}
