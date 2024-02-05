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

int main() {
  FastIO;
  vector<string> clocks{"I",   "II",   "III", "IIII", "V",  "VI",
                        "VII", "VIII", "IX",  "X",    "XI", "XII"};
  string s;
  int t;
  cin >> s >> t;

  int idx{};
  rep(i, 12) {
    if (clocks[i] == s) idx = i;
  }
  idx = (idx + t + 1200) % 12;
  output(clocks[idx]);
}
