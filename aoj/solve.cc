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

void bubbleSort(vector<int>& ai, int n) {
  int cnt{};
  bool finished{true};
  while (finished) {
    finished = false;
    for (int i = n - 1; i >= 1; --i) {
      if (ai[i] < ai[i - 1]) {
        int tmp = ai[i];
        ai[i] = ai[i - 1];
        ai[i - 1] = tmp;
        finished = true;
        cnt++;
      }
    }
  }

  rep(i, n) cout << ai[i] << (i == n - 1 ? '\n' : ' ');
  output(cnt);
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  bubbleSort(ai, n);
}
