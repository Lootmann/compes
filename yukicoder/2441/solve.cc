#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

using vvi = vector<vector<int>>;
using vi = vector<int>;

vvi mul(vvi a, vvi b) {
  vvi res(2, vi(2, 0));

  rep(i, 2) {
    rep(j, 2) {
      rep(k, 2) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return res;
}

int main() {
  FastIO;
  vvi mat(2, vi(2, 0));

  rep(i, 2) rep(j, 2) {
    cin >> mat[i][j];
  }

  vvi res = mul(mul(mat, mat), mat);

  cout << res[0][0] << ' ' << res[0][1] << '\n';
  cout << res[1][0] << ' ' << res[1][1] << '\n';
}
