#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define repa(i, a, n) for (int i = a; (int)(i) < (n); (++i))
#define rrep(i, n) for (int i = (n - 1); (int)i >= 0; --i)
#define rrepa(i, a, n) for (int i = a; (int)i >= 0; --i)
#define EACH(x, a) for (auto& x : a)
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
using ullint = unsigned long long int;

ullint conv2to10(const string& s) {
  ullint total{};
  rep(i, (int)s.size()) {
    total *= 2;
    if (s[i] == '1') {
      total += 1;
    }
  }
  return total;
}

int main() {
  FastIO;
  string a, b;
  cin >> a >> b;

  ullint aa = conv2to10(a);
  ullint bb = conv2to10(b);

  if (aa % 2 == 1 && bb % 2 == 1)
    output("Odd");
  else
    output("Even");
}
