#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do {cout << msg << endl;exit(0);} while (0)
#define el '\n'

#define all(k)  k.begin(), k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

struct UnionFind {
  vector<int> par, rank;

  UnionFind(int n) {
    par.resize(n);
    rank.resize(n);
    rep(i, n) {
      par[i] = i, rank[i] = 0;
    }
  }

  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
  bool same(int x, int y) { return root(x) == root(y); }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  rep(_, q) {
    int p, a, b;
    cin >> p >> a >> b;

    if (p == 0) {
      uf.unite(a, b);
    } else {
      if (uf.same(a, b)) {
        cout << "Yes" << el;
      } else {
        cout << "No" << el;
      }
    }
  }
}
