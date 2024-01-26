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
  set<string> cards;

  int n;
  cin >> n;
  rep(_, n) {
    string s, t;
    cin >> s >> t;
    cards.insert(s + t);
  }

  for (auto c : vector<char>{'S', 'H', 'C', 'D'}) {
    for (int i = 1; i <= 13; ++i) {
      string missing = c + to_string(i);
      if (cards.find(missing) == cards.end()) {
        cout << missing[0] << ' ' << missing.substr(1) << '\n';
      }
    }
  }
}
