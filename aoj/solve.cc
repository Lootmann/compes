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

void selectionSort(vector<int>& ai, int n) {
  int cnt{};

  rep(i, n) {
    int minj = i;
    for (int j = i; j < n; ++j) {
      if (ai[j] < ai[minj]) {
        minj = j;
      }
    }

    if (ai[i] != ai[minj]) {
      int tmp = ai[i];
      ai[i] = ai[minj];
      ai[minj] = tmp;
      cnt++;
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

  selectionSort(ai, n);
}
