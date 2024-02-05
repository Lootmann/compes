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

vector<int> get_input(int n) {
  set<int> st;
  rep(i, n) {
    int x;
    cin >> x;
    st.insert(x);
  }
  vector<int> res;
  for (auto s : st) {
    res.push_back(s);
  }
  return res;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<int> xi = get_input(n);
  if (xi.size() == 1) die(0);
  int min_dist{100000000};
  rep(i, (int)xi.size() - 1) {
    chmin(min_dist, abs(xi[i] - xi[i + 1]));
  }
  output(min_dist);
}
