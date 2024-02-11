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

vector<int> split_by_plus(const string& s) {
  vector<string> sp;
  int prev{0};
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '+') {
      sp.push_back(s.substr(prev, i - prev));
      prev = i + 1;
    }
  }
  sp.push_back(s.substr(prev));

  vector<int> nums;
  for (auto eq : sp) {
    int num{1};
    for (auto ch : eq) {
      if (ch == '0') {
        num = 0;
      }
    }
    nums.push_back(num);
  }

  return nums;
}

int main() {
  string s;
  cin >> s;

  vector<int> vs = split_by_plus(s);

  int cnt{};
  for (auto num : vs) {
    if (num != 0) {
      cnt++;
    }
  }
  dump(vs);
  out(cnt);
}
