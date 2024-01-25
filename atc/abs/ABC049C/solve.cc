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
#define INTi 1 << 30
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
  string s;
  cin >> s;

  set<string> st{"dream", "dreamer", "erase", "eraser"};

  int len = (int)s.size();
  int idx{len};

  while (idx != 0) {
    bool is_ok{false};
    int back_pos{};

    if (st.contains(s.substr(idx - 5, 5))) {
      is_ok = true;
      back_pos = 5;
    } else if (st.contains(s.substr(idx - 6, 6))) {
      is_ok = true;
      back_pos = 6;
    } else if (st.contains(s.substr(idx - 7, 7))) {
      is_ok = true;
      back_pos = 7;
    }

    if (!is_ok) break;
    idx -= back_pos;
  }

  if (idx == 0)
    output("YES");
  else
    output("NO");
}
