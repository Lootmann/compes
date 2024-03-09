#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
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

int slot(int cnt, vector<string> reel, const char number) {
  int idx{}, ans{};

  while (cnt != 0) {
    rep(i, (int)reel.size()) {
      if (reel[i][idx] == number) {
        reel[i][idx] = '.';
        cnt--;
        break;
      }
    }

    idx = (idx + 1) % 10;
    ans++;
  }

  return ans - 1;
}

int main() {
  int n;
  cin >> n;

  vector<string> reel;
  rep(_, n) {
    string s;
    cin >> s;
    reel.push_back(s);
  }

  int ans{INFi};
  rep(i, 10) {
    chmin(ans, slot(n, reel, (char)(i + '0')));
  }
  cout << ans << el;
}
