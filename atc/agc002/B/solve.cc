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
#define INTi 1 << 30
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
  int N, M;
  cin >> N >> M;

  vector<int> cards(N, 1);
  vector<bool> box(N, false);
  box[0] = true;

  rep(_, M) {
    int x, y;
    cin >> x >> y;
    x--, y--;

    if (box[x]) {
      box[y] = true;
    }
    cards[x]--;
    cards[y]++;

    if (cards[x] == 0) {
      box[x] = false;
    }
  }

  int cnt{};
  for (auto b : box) {
    if (b) cnt++;
  }
  output(cnt);
}
