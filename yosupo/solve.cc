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

vector<llint> factorize(llint n) {
  vector<llint> res;

  for (llint i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }

  if (n != 1) {
    res.push_back(n);
  }

  return res;
}

int main() {
  FastIO;
  int q;
  cin >> q;

  rep(_, q) {
    llint a;
    cin >> a;

    vector<llint> ans = factorize(a);
    sort(ans.begin(), ans.end());

    int n = (int)ans.size();
    if (n == 0) {
      cout << n << '\n';

    } else {
      cout << n << ' ';
      rep(i, n) {
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
      }
    }
  }
}
