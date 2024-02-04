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
  int n, m;
  cin >> n >> m;

  n--;
  vector<int> cup(3, 0);
  cup[n] = 1;

  rep(_, m) {
    int p, q;
    cin >> p >> q;
    p--, q--;

    auto tmp = cup[p];
    cup[p] = cup[q];
    cup[q] = tmp;
    dump(p, q, cup);
  }

  rep(i, 3) {
    if (cup[i] == 1) {
      die(i + 1);
    }
  }
}
