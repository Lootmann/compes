#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(k) k.begin(), k.end()

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;
using vs = vector<string>;

void out(const vs& res, const int n) {
  rep(i, n) {
    cout << res[i] << '\n';
  }
}

void solve(vs& dna, vs& answer, const int n) {
  reverse(dna.begin(), dna.end());

  string res{};
  for (auto line : dna) {
    res += line;
  }

  rep(i, n) {
    answer[i] = res.substr(n * i, n);
  }
}

int main() {
  FastIO;
  int n, m;
  cin >> n >> m;

  vs dna(m);
  rep(i, m) cin >> dna[i];

  // init padding '.'
  vs ans(n, string(n, '.'));

  solve(dna, ans, n);
  out(ans, n);
}
