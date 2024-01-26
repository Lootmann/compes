#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

struct Dice {
  int one, two, three, four, five, six;
  Dice(int o, int tw, int th, int fo, int fi, int s)
      : one(o), two(tw), three(th), four(fo), five(fi), six(s) {}

  // direction
  void move(char d) {
    if (d == 'N') {
      int tmp = one;
      one = two;
      two = six;
      six = five;
      five = tmp;
    } else if (d == 'S') {
      int tmp = one;
      one = five;
      five = six;
      six = two;
      two = tmp;
    } else if (d == 'E') {
      int tmp = one;
      one = four;
      four = six;
      six = three;
      three = tmp;
    } else {
      int tmp = one;
      one = three;
      three = six;
      six = four;
      four = tmp;
    }
  }
};

int main() {
  FastIO;
  int one, two, three, four, five, six;
  cin >> one >> two >> three >> four >> five >> six;

  Dice d(one, two, three, four, five, six);

  string s;
  cin >> s;
  for (auto ch : s) {
    d.move(ch);
    dump(d.one);
  }
  output(d.one);
}
