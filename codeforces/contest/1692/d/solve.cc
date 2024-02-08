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

bool is_palindrome(int hhmm) {
  int hh = hhmm / 60;
  int mm = hhmm % 60;
  return (hh / 10 == mm % 10) && (hh % 10 == mm / 10);
}

int palindrome_counter(const string& hhmm, const int& rot) {
  int cur = stoi(hhmm.substr(0, 2)) * 60 + stoi(hhmm.substr(3, 2));

  set<int> st;

  // max rot?
  rep(_, 24 * 60) {
    st.insert(cur);
    cur += rot;
    cur %= 1440;
  }

  int cnt{};
  for (auto key : st) {
    if (is_palindrome(key)) {
      cnt++;
    }
  }
  return cnt;
}

void solve() {
  string hhmm;
  int n;
  cin >> hhmm >> n;
  out(palindrome_counter(hhmm, n));
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
