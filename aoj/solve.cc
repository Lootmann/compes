#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
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
using P = pair<int, int>;

int main() {
  FastIO;
  string S;
  cin >> S;

  stack<int> st;
  vector<P> ans;

  int cnt{0}, n = (int)S.size();

  for (int i = 0; i < n; i++) {
    if (S[i] == '\\') {
      st.push(i);
    } else if (S[i] == '/') {
      if (st.empty()) continue;
      int a = i - st.top();
      cnt += a;

      while (!ans.empty() && st.top() < ans.back().second) {
        a += ans.back().first;
        ans.pop_back();
      }

      ans.push_back({a, st.top()});
      st.pop();
    }
  }

  int nn = (int)ans.size();

  cout << cnt << endl;
  cout << nn << (nn ? " " : "");

  for (int i = 0; i < nn; i++) {
    cout << ans[i].first << (i == nn - 1 ? "" : " ");
  }
  cout << endl;
}
