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

void gen_lucky_numbers(set<int>& st, string s) {
  if (s != "" && stoi(s) >= 1000) return;

  st.insert(stoi(s + "4"));
  gen_lucky_numbers(st, s + "4");

  st.insert(stoi(s + "7"));
  gen_lucky_numbers(st, s + "7");
}

void solve() {
  int n;
  cin >> n;

  set<int> lucky_numbers;
  gen_lucky_numbers(lucky_numbers, "");

  dump(lucky_numbers);

  for (auto num : lucky_numbers) {
    if (n % num == 0) die("YES");
  }

  output("NO");
}

int main() {
  FastIO;
  int t{3};
  while (t--) solve();
}
