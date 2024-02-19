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
#define el '\n'

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
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> pairs;
  map<int, vector<int>> mp;

  rep(i, m) {
    int p, y;
    cin >> p >> y;
    pairs.push_back({p, y});
    mp[p].push_back(y);
  }

  map<pair<int, int>, int> city;
  for (auto& [num, vs] : mp) {
    sort(all(vs));

    rep(i, (int)vs.size()) {
      city[{num, vs[i]}] = i + 1;
    }
  }

  auto fill = [](int num) {
    string k = to_string(num);
    if (num < 10) return "00000" + k;
    if (num < 100) return "0000" + k;
    if (num < 1000) return "000" + k;
    if (num < 10000) return "00" + k;
    if (num < 100000) return "0" + k;
    return k;
  };

  for (auto p : pairs) {
    cout << fill(p.first) << fill(city[p]) << el;
  }
}
