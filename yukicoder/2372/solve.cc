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

void solve(vector<string>& ai) {
  string s;
  cin >> s;
  ai.push_back(s);
}

void asakatsu(vector<string>& ai, const int N, const int K) {
  vector<string> ti(6);
  vector<int> di(6);
  rep(i, 6) cin >> ti[i] >> di[i];

  int idx = max(0, (int)ai.size() - N);
  rep(i, 6) {
    bool exists = false;
    for (int j = idx; j < (int)ai.size(); ++j) {
      if (ai[j] == ti[i]) exists = true;
      if (exists) chmin(di[i], K);
    }
  }

  // solver
  int total{}, cnt{};
  rep(i, 6) {
    if (total + di[i] <= 60) {
      cnt++;
      total += di[i];
    } else {
      break;
    }
  }

  // output
  output(cnt);

  rep(i, cnt) {
    ai.push_back(ti[i]);
  }
}

int main() {
  FastIO;
  int N, K, Q;
  cin >> N >> K >> Q;

  bool no_solve{true};
  set<string> st;

  vector<string> ai;

  rep(_, Q) {
    int query;
    cin >> query;

    if (query == 1) {
      solve(ai);
    } else {
      no_solve = false;
      asakatsu(ai, N, K);
    }
  }

  if (no_solve) cout << '\n';
}
