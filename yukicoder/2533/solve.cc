#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

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

using llint = long long int;

string int2bit(int n) {
  if (n == 0) return "0";

  string res{};
  while (n > 0) {
    res = (char)(n % 2 + '0') + res;
    n /= 2;
  }
  return res;
}

int main() {
  FastIO;
  int a, b;
  cin >> a >> b;

  string sa = int2bit(a);
  string sb = int2bit(b);

  // sa's first bit is 1
  if (sa.size() > sb.size()) die("No");

  int n = min((int)sa.size(), (int)sb.size());

  rep(i, n) {
    char ach = sa[(int)sa.size() - i - 1];
    char bch = sb[(int)sb.size() - i - 1];
    if (ach == '1') {
      if (bch == '0') die("No");
    }
  }

  out("Yes");
}
