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
  vector<int> cards(14, 0);
  rep(i, 5) {
    int a;
    cin >> a;
    cards[a]++;
  }
  dump(cards);

  int over{}, three{}, two{};
  rep(i, (int)cards.size()) {
    if (cards[i] >= 4) over++;
    if (cards[i] == 3) three++;
    if (cards[i] == 2) two++;
  }

  if (over == 1) {
    output("NO HAND");
  } else if (three == 1 && two == 1) {
    output("FULL HOUSE");
  } else if (three == 1) {
    output("THREE CARD");
  } else if (two == 2) {
    output("TWO PAIR");
  } else if (two == 1) {
    output("ONE PAIR");
  } else {
    output("NO HAND");
  }
}
