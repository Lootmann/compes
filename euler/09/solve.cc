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

  set<int> ans;

  for (int i = 0; i <= 1000; ++i) {
    for (int j = i + 1; j <= 1000; ++j) {
      int k = 1000 - i - j;
      if (0 <= k && k <= 1000 && i < j && j < k && i * i + j * j == k * k) {
        ans.insert(i * j * k);
      }
    }
  }

  for (auto a : ans) {
    cout << a << ' ';
  }
  cout << endl;
}
