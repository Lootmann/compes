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

bool is_ok(vector<int> vi) {
  bool ok{false};
  int a1 = vi[0], a2 = vi[1], a3 = vi[2];

  if (a2 > a1 && a1 > a3) ok = true;
  if (a2 > a3 && a3 > a1) ok = true;

  if (a2 < a1 && a1 < a3) ok = true;
  if (a2 < a3 && a3 < a1) ok = true;

  return ok;
}

int main() {
  FastIO;
  vector<int> vi(3);
  rep(i, 3) {
    char c;
    cin >> c;
    if (c == '?')
      vi[i] = 0;
    else
      vi[i] = c - '0';
  }
  dump(vi);

  vector<int> t1 = vi, t2 = vi;
  rep(i, 3) {
    if (t1[i] == 0) {
      t1[i] = 1;
    }
  }

  rep(i, 3) {
    if (t2[i] == 0) {
      t2[i] = 4;
    }
  }

  int cnt{};
  if (is_ok(t1)) cnt += 1;
  if (is_ok(t2)) cnt += 2;
  dump(cnt);

  if (cnt == 1)
    output(1);
  else if (cnt == 2)
    output(4);
  else if (cnt == 3)
    output(14);
}
