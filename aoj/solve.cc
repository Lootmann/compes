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

void vector_swap(vector<int>& vs, int left, int right) {
  for (int i = 0; i < (right - left) / 2; ++i) {
    int tmp = vs[i + left];
    vs[i + left] = vs[right - i - 1];
    vs[right - i - 1] = tmp;
  }
  return;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  int q;
  cin >> q;
  rep(_, q) {
    int left, right;
    cin >> left >> right;
    vector_swap(ai, left, right);
    dump(ai);
  }

  rep(i, n) {
    cout << ai[i] << (i == n - 1 ? '\n' : ' ');
  }
}
