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

bool is_leading_zero(const string s) {
  int zero_idx{};
  rep(i, (int)s.size()) {
    if (s[i] == '0') {
      zero_idx = i;
      break;
    }
  }

  int digit{};
  rep(i, (int)s.size()) {
    if (s[i] != '0') {
      digit = i;
      break;
    }
  }

  return digit > zero_idx;
}

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  vector<int> si(m);
  vector<char> ci(m);
  rep(i, m) {
    int s, c;
    cin >> s >> c;
    si[i] = s;
    ci[i] = c + '0';
  }

  int min_num{1000};
  for (int i = 0; i <= 999; ++i) {
    string str = to_string(i);
    bool is_ok{true};

    rep(j, m) {
      int s = si[j];
      char c = ci[j];
      s--;

      if (s > (int)str.size()) is_ok = false;
      if (str[s] != c) is_ok = false;
    }

    if (is_ok && (int)str.size() == n) {
      chmin(min_num, i);
    }
  }

  dump(min_num);
  if (min_num == 1000)
    output(-1);
  else
    output(min_num);
}
