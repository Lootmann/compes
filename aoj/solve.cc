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

void out(const vector<int>& ai, int n) {
  rep(i, n) {
    cout << ai[i] << (i == n - 1 ? '\n' : ' ');
  }
}

void insertionSort(vector<int>& ai, int n) {
  out(ai, n);

  for (int i = 1; i < n; ++i) {
    int v = ai[i];
    int j = i - 1;
    while (j >= 0 && ai[j] > v) {
      ai[j + 1] = ai[j];
      j--;
    }
    ai[j + 1] = v;

    out(ai, n);
  }
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  insertionSort(ai, n);
}
