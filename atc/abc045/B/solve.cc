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

queue<char> get_input() {
  string s;
  cin >> s;

  queue<char> que;
  for (auto ch : s) {
    que.push(ch);
  }
  return que;
}

int main() {
  queue<char> a = get_input(), b = get_input(), c = get_input();

  // simulation
  char now = a.front();
  a.pop();

  while (true) {
    if (now == 'a') {
      if (a.empty()) break;

      now = a.front();
      a.pop();

    } else if (now == 'b') {
      if (b.empty()) break;
      now = b.front();
      b.pop();

    } else {
      if (c.empty()) break;
      now = c.front();
      c.pop();
    }
  }

  out((char)(now - 'a' + 'A'));
}
