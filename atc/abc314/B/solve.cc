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
  vector<set<int>> vs(n);
  rep(i, n) {
    int c;
    cin >> c;

    set<int> ai;
    rep(_, c) {
      int a;
      cin >> a;
      ai.insert(a);
    }
    vs[i] = ai;
  }

  int x;
  cin >> x;

  vector<pair<int, int>> hits;
  rep(i, n) {
    auto s = vs[i];
    dump(s);
    if (s.find(x) != s.end()) {
      hits.push_back(make_pair(s.size(), i + 1));
    }
  }

  sort(all(hits));

  int min_hit{100000};
  for (auto hit : hits) {
    chmin(min_hit, hit.first);
  }

  vector<int> ans;
  for (auto hit : hits) {
    if (hit.first == min_hit) {
      ans.push_back(hit.second);
    }
  }

  output(ans.size());
  rep(i, (int)ans.size()) {
    cout << ans[i] << (i == (int)ans.size() - 1 ? '\n' : ' ');
  }
}
