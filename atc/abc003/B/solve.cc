#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do {cout << msg << endl;exit(0);} while (0)

#define all(k)  k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

int count_ch(map<char, int>& mp) {
  int at_count{};

  for (auto key : mp) {
    if (key.first == '@') {
      at_count += key.second;
    }
  }

  return at_count;
}

bool is_atcoder(char ch) {
  return ch == 'a' || ch == 't' || ch == 'c' || ch == 'o' || ch == 'd' ||
         ch == 'e' || ch == 'r';
}

int main() {
  string s, t;
  cin >> s >> t;

  rep(i, (int)s.size()) {
    if (s[i] == t[i]) continue;
    if (s[i] == '@' && is_atcoder(t[i])) continue;
    if (t[i] == '@' && is_atcoder(s[i])) continue;
    die("You will lose");
  }

  out("You can win");
}
