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

bool is_br(char ch) {
  return ch == 'B' || ch == 'R';
}

bool is_white(char ch) {
  return ch == 'W';
}

vector<string> split_w(string& s) {
  s += "W";

  vector<string> res;
  int prev{};
  rep(i, (int)s.size()) {
    if (s[i] == 'W') {
      string sp = s.substr(prev, i - prev);
      if (sp != "") {
        res.push_back(sp);
      }
      prev = i + 1;
    }
  }

  return res;
}

void solve() {
  int n;
  string s;
  cin >> n >> s;

  auto res = split_w(s);
  dump(res);

  for (auto chunk : res) {
    if (chunk == "") continue;
    int red{}, blue{};
    for (auto ch : chunk) {
      if (ch == 'R')
        red++;
      else
        blue++;
    }

    if (red == 0 || blue == 0) {
      out("NO");
      return;
    }
  }

  out("YES");
}

int main() {
  FastIO;
  int t;
  cin >> t;
  while (t--) solve();
}
