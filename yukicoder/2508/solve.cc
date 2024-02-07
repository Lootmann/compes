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

/*
 * a(x - p)(x - q)  = axx + bx + c
 *
 * b = -a(p+q)
 * c = apq
 *
 * bb > 4ac <-> bb - 4ac > 0
 * aa(pp + 2pq + qq) - 4aapq > 0
 * pp - 2pq + qq > 0
 * (p - q)(p - q) > 0
 *
 * p == q のときのみ bb > 4ac が成り立たない
 * */
int main() {
  FastIO;
  string a, p, q;
  cin >> a >> p >> q;

  if (p == q)
    out("No");
  else
    out("Yes");
}
