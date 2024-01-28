#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
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

struct Team {
  int id;
  int region;
  int correct;
  int penalty;
  Team() {}
};

bool compare(const Team& l, const Team& r) {
  if (l.correct > r.correct)
    return true;
  else if (l.correct < r.correct)
    return false;

  else {
    if (l.penalty < r.penalty)
      return true;
    else if (l.penalty > r.penalty)
      return false;
    else {
      return l.id < r.id;
    }
  }
  return false;
}

void solve(vector<Team> vt) {
  int pass{};
  map<int, int> mp;

  for (auto team : vt) {
    bool passed{false};
    int region = team.region;

    if (pass < 10) {
      if (mp.find(region) == mp.end()) {
        mp[region]++;
        passed = true;
      } else if (mp[region] < 3) {
        mp[region]++;
        passed = true;
      }
    } else if (pass < 20) {
      if (mp.find(region) == mp.end()) {
        mp[region]++;
        passed = true;
      } else if (mp[region] < 2) {
        mp[region]++;
        passed = true;
      }
    } else if (pass < 26) {
      if (mp.find(region) == mp.end()) {
        mp[region]++;
        passed = true;
      }
    }

    if (passed) {
      cout << team.id << '\n';
      pass++;
    }
  }
}

int main() {
  FastIO;
  int n;
  while (cin >> n) {
    if (n == 0) break;

    // input
    vector<Team> vt(n);
    rep(i, n) cin >> vt[i].id >> vt[i].region >> vt[i].correct >> vt[i].penalty;
    sort(vt.begin(), vt.end(), compare);

    solve(vt);
  }
}
