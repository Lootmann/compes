#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do {cout << msg << endl;exit(0);} while (0)

#define all(k)  k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> times(n, vector<int>(n, 0));
  rep(i, n) rep(j, n) cin >> times[i][j];

  vector<int> city;
  rep(i, n - 1) city.push_back(i + 1);

  int ans{};
  do {
    int cnt = times[0][city.front()];
    rep(i, n - 2) cnt += times[city[i]][city[i + 1]];
    cnt += times[city.back()][0];

    if (cnt == k) {
      ans++;
    }

  } while (next_permutation(all(city)));

  out(ans);
}
