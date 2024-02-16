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
#define el '\n'

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

int main() {
  string s;
  cin >> s;

  sort(all(s));

  int n = (int)s.size();
  llint ans{};

  // 1 2345
  // 12 345
  // 123 45
  // 1234 5
  do {
    for (int i = 1; i < n; ++i) {
      string head = s.substr(0, i);
      string tail = s.substr(i);

      if (head[0] == '0') continue;
      if (tail[0] == '0') continue;

      llint t = stoll(head) * stoll(tail);
      if (chmax(ans, t)) {
        dump(head, tail);
      }
    }
  } while (next_permutation(all(s)));

  out(ans);
}
