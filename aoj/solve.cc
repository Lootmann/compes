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
  Dice() {}
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

  // xxxxxx
  int die_number() {
    return 100000 * one + 10000 * two + 1000 * three + 100 * four + 10 * five +
           six;
  }
};

Dice input() {
  int one, two, three, four, five, six;
  cin >> one >> two >> three >> four >> five >> six;
  return Dice(one, two, three, four, five, six);
}

bool is_same_dice(Dice d1, Dice d2) {
  for (auto direction : "NNNNWNNNWNNNENNNENNNWNNN") {
    d1.move(direction);
    if (d1.die_number() == d2.die_number()) {
      return true;
    }
  }
  return false;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<Dice> dices;
  rep(_, n) {
    Dice d = input();
    dices.push_back(d);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (is_same_dice(dices[i], dices[j])) {
        die("No");
      }
    }
  }
  output("Yes");
}
