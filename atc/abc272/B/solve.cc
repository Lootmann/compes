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

  vector<vector<int>> counts(n, vector<int>(n, 0));
  rep(i, n) counts[i][i] = 100;

  rep(_, m) {
    int k;
    cin >> k;

    vector<int> tmp;
    rep(__, k) {
      int x;
      cin >> x;
      x--;
      tmp.push_back(x);
    }

    for (int i = 0; i < k; ++i) {
      for (int j = i + 1; j < k; ++j) {
        counts[tmp[i]][tmp[j]]++;
        counts[tmp[j]][tmp[i]]++;
      }
    }
  }

  bool not_meet{false};
  rep(i, n) {
    rep(j, n) {
      if (counts[i][j] == 0) not_meet = true;
    }
  }

  if (not_meet)
    output("No");
  else
    output("Yes");
}
