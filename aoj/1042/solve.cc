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

vector<int> count_word(const string& s) {
  vector<int> res;
  int cnt{};
  for (auto ch : s) {
    if (ch == ' ') {
      res.push_back(cnt);
      cnt = 0;
    } else {
      cnt++;
    }
  }
  res.push_back(cnt);
  return res;
}

int main() {
  FastIO;
  string s;
  while (getline(cin, s)) {
    if (s == "END OF INPUT") break;
    auto res = count_word(s);
    for (auto c : res) {
      cout << c;
    }
    cout << '\n';
  }
}
