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

string ceaser(const string& s, int m) {
  string res{};
  for (auto ch : s) {
    res += char((ch - 'a' + m) % 26 + 'a');
  }
  return res;
}

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  vector<string> plain(n);
  map<string, int> mp;

  // 200,000
  rep(i, n) {
    cin >> plain[i];

    // 26
    rep(j, 26) {
      string crypto = ceaser(plain[i], j);
      mp[crypto] = i;
    }
  }

  // 200,000
  int q;
  cin >> q;

  rep(_, q) {
    string enc;
    cin >> enc;
    int idx = mp[enc];
    output(plain[idx]);
  }
}
