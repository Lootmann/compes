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

  int d;
  cin >> d;
  set<int> st;
  rep(_, d) {
    int e;
    cin >> e;
    st.insert(e);
  }

  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> res{bit};
    int cnt{};

    rep(i, n) {
      if (bit & (1 << i)) {
        if (st.find(i) != st.end()) cnt++;
        res.push_back(i);
      }
    }

    if (res.size() >= st.size() + 1 && cnt == (int)st.size()) {
      cout << res[0] << ":";
      for (int i = 1; i < (int)res.size(); ++i) {
        cout << ' ' << res[i];
      }
      cout << '\n';
    }
  }
}
