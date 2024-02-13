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

using P = pair<string, int>;

bool compare(const P& a, const P& b) {
  return a.second > b.second;
}

int main() {
  int n;
  cin >> n;

  vector<P> mountains(n);
  rep(i, n) {
    string name;
    int height;
    cin >> name >> height;
    mountains[i] = make_pair(name, height);
  }

  sort(all(mountains), compare);

  rep(i, n) {
    dump(mountains[i]);
  }

  cout << mountains[1].first << '\n';
}
