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

string conv(int hh, int mm, int ss) {
  string res{};

  if (hh < 10) res += "0";
  res += to_string(hh);

  res += ":";

  if (mm < 10) res += "0";
  res += to_string(mm);

  res += ":";

  if (ss < 10) res += "0";
  res += to_string(ss);

  return res;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  int hh = n / 3600;
  n %= 3600;
  int mm = n / 60;
  n %= 60;
  int ss = n;

  out(conv(hh, mm, ss));
}
