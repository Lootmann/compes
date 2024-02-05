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
  vector<vector<string>> village(n, vector<string>(n));
  rep(i, n) {
    rep(j, n) {
      string msg;
      cin >> msg;
      village[i][j] = msg;
    }
  }

  int cnt{}, ans{};
  rep(w, n) {
    bool nyanpass{true};
    rep(h, n) {
      if (h != w) {
        if (village[h][w] != "nyanpass") {
          nyanpass = false;
        }
      }
    }

    if (nyanpass) {
      ans = w + 1;
      cnt++;
    }
  }

  if (cnt == 1)
    output(ans);
  else
    output(-1);
}
