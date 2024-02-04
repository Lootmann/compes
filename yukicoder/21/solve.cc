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
  int n, k;
  cin >> n >> k;

  vector<int> ps(n);
  rep(i, n) cin >> ps[i];
  sort(all(ps));

  double ans{0};
  do {
    for (int a = 0; a < n; ++a) {
      for (int b = a + 1; b < n; ++b) {
        for (int c = b + 1; c < n; ++c) {
          int low{}, mid{}, high{};

          for (int t = 0; t <= a; ++t) low += ps[t];
          for (int t = a + 1; t <= b; ++t) mid += ps[t];
          for (int t = b + 1; t <= c; ++t) high += ps[t];

          int cnt = (a + 1) + (b - a) + (c - b);
          if (cnt == k) {
            double ave_a = (double)low / (a + 1);
            double ave_b = (double)mid / (b - a);
            double ave_c = (double)high / (c - b);

            double diff =
                max(ave_a, max(ave_b, ave_c)) - min(ave_a, min(ave_b, ave_c));
            chmax(ans, diff);
          }
        }
      }
    }
  } while (next_permutation(all(ps)));

  output(ans);
}
