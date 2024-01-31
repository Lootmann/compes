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
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  vector<int> counter(n, 0);
  for (auto a : ai) {
    counter[a - 1]++;
  }

  int total{};
  rep(i, n) {
    // find empty
    if (counter[i] == 0) {
      rep(j, n) {
        if (counter[j] > 1) {
          counter[i]++;
          counter[j]--;
          total += abs(j - i);
          break;
        }
      }
    }
    dump(total, counter);
  }

  output(total);
}
