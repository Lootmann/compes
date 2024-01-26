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
  int N;
  cin >> N;

  string s;
  cin >> s;

  vector<int> west(N + 1, 0), east(N + 1, 0);
  for (int i = 0; i < N; ++i) {
    if (s[i] == 'W') {
      west[i]++;
    } else {
      east[i]++;
    }

    if (i > 0) {
      west[i] += west[i - 1];
      east[i] += east[i - 1];
    }
  }

  int ans{INFi};
  rep(i, N) {
    int sum{};
    if (i != 0) {
      sum += west[i - 1];
    }
    sum += east[N - 1] - east[i];
    chmin(ans, sum);
  }
  output(ans);
}
