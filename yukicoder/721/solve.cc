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

tuple<int, int, int> conv(string s) {
  int yy = stoi(s.substr(0, 4));
  int mm = stoi(s.substr(5, 2));
  int dd = stoi(s.substr(8));
  return {yy, mm, dd};
}

int main() {
  FastIO;
  string s;
  cin >> s;
  auto [yy, mm, dd] = conv(s);

  dd += 2;

  vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0) {
    days[1]++;
  }

  if (dd > days[mm - 1]) {
    dd -= days[mm - 1];
    mm++;
  }

  if (mm > 12) {
    mm -= 12;
    yy++;
  }
  cout << yy << '/';

  if (mm < 10)
    cout << 0 << mm;
  else
    cout << mm;
  cout << '/';

  if (dd < 10)
    cout << 0 << dd;
  else
    cout << dd;
  cout << endl;

  return 0;
}
