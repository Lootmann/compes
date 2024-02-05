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
  string left{"(^^*)"}, right{"(*^^)"};
  string s;
  cin >> s;

  int l{}, r{};
  int n = (int)s.size();
  for (int i = 0; i < n; i += 5) {
    if (s[i] == '#') break;
    string face = s.substr(i, 5);

    if (face == left) l++;
    if (face == right) r++;
  }

  cout << l << ' ' << r << endl;
}
