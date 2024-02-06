#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define all(k) k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

struct Pair {
  double frac;
  int a;
  int b;
};

bool compare(const Pair& a, const Pair& b) {
  return a.frac > b.frac;
}

int main() {
  FastIO;
  vector<Pair> vp;
  int n;
  cin >> n;
  rep(_, n) {
    int a, b;
    cin >> a >> b;

    Pair p;
    p.frac = (double)a / b;
    p.a = a;
    p.b = b;
    vp.push_back(p);
  }

  sort(all(vp), compare);

  rep(i, n) {
    cout << vp[i].a << ' ' << vp[i].b << '\n';
  }
}
