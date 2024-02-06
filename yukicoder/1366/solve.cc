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

bool check(vector<int> ai) {
  if (ai[1] < ai[0] && ai[0] < ai[2]) return true;
  if (ai[1] < ai[2] && ai[2] < ai[0]) return true;
  if (ai[1] > ai[0] && ai[0] > ai[2]) return true;
  if (ai[1] > ai[2] && ai[2] > ai[0]) return true;
  return false;
}

int main() {
  FastIO;
  vector<int> ai(3), bi(3);
  rep(i, 3) cin >> ai[i];
  rep(i, 3) cin >> bi[i];

  bool can_kadomatsu{false};
  rep(i, 3) {
    rep(j, 3) {
      swap(ai[i], bi[j]);
      if (check(ai) && check(bi)) {
        can_kadomatsu = true;
      }
      swap(ai[i], bi[j]);
    }
  }
  if (can_kadomatsu)
    output("Yes");
  else
    output("No");
}
