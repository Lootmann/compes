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

vector<int> gen_left(const string& s, const int n) {
  vector<int> ai(n);
  set<char> st;
  int cnt{};

  rep(i, n) {
    if (st.find(s[i]) == st.end()) {
      st.insert(s[i]);
      cnt++;
    }

    ai[i] = cnt;
  }

  return ai;
}

vector<int> gen_right(const string& s, const int n) {
  vector<int> ai(n);
  set<char> st;
  int cnt{};

  for (int i = n - 1; i >= 0; --i) {
    if (st.find(s[i]) == st.end()) {
      st.insert(s[i]);
      cnt++;
    }
    ai[i] = cnt;
  }

  return ai;
}

void solve() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> left = gen_left(s, n), right = gen_right(s, n);

  int max_cnt{};
  rep(i, n - 1) {
    chmax(max_cnt, left[i] + right[i + 1]);
  }
  out(max_cnt);
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
