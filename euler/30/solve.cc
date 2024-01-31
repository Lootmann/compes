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

const int POW = 5;

llint calc(string digit) {
  llint res{};
  for (auto ch : digit) {
    res += powl(llint(ch - '0'), POW);
  }
  return res;
}

int main() {
  FastIO;

  string cur{};
  llint sum{};
  for (int i = 2; i <= 99999; ++i) {
    if (i % 100000 == 0)
      cerr << "[" << i << "] -> " << sum << " {" << cur << "}" << endl;
    llint res = calc(to_string(i));
    if (i == res) {
      dump(i);
      sum += i;
      cur += to_string(i) + ",";
    }
  }
  output(sum);
}
