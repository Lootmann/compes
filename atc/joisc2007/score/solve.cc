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

struct Team {
  int score;
  int id;
};

bool compare(const Team& a, const Team& b) {
  return a.score > b.score;
}

void solve(const vector<Team>& vs) {
  vector<Team> tmp = vs;
  sort(all(tmp), compare);

  map<int, int> mp;
  int rank{1}, prev{-1}, cnt{0};

  for (auto [score, id] : tmp) {
    if (prev == score) {
      mp[id] = rank;
      cnt++;
    } else {
      rank += cnt;
      cnt = 1;
      mp[id] = rank;
    }
    prev = score;
  }

  for (auto [score, id] : vs) {
    cout << mp[id] << el;
  }
}

int main() {
  int n;
  cin >> n;

  vector<Team> teams(n);
  rep(i, n) {
    cin >> teams[i].score;
    teams[i].id = i + 1;
  }

  solve(teams);
}
