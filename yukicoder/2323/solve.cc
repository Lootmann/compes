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

using llint = long long int;

int main() {
  FastIO;
  string a, b;
  cin >> a >> b;

  int aa = (int)a.size();
  int bb = (int)b.size();

  if (aa > bb) {
    rep(i, aa - bb) b = '0' + b;
  } else if (aa < bb) {
    rep(i, bb - aa) a = '0' + a;
  }

  vector<int> carryup(max(aa, bb), 0);
  rep(i, max(aa, bb)) {
    if (a[i] == '1') carryup[i]++;
    if (b[i] == '1') carryup[i]++;
  }

  string s{};
  rep(i, max(aa, bb)) {
    if (carryup[i] == 1)
      s = s + '1';
    else
      s = s + '0';
  }

  int ans{};
  for (auto ch : s) {
    ans *= 2;
    if (ch == '1') {
      ans += 1;
    }
  }

  output(ans);
}
