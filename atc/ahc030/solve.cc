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

struct P {
  int i;
  int j;
};

using VVP = vector<vector<P>>;
using VP = vector<P>;

VVP get_fields(int M) {
  VVP fields(M);

  rep(i, M) {
    int d;
    cin >> d;

    vector<P> di(d);
    rep(j, d) {
      P p;
      cin >> p.i >> p.j;
      di.push_back(p);
    }
    fields[i] = di;
  }

  return fields;
}

VP solver(const VVP& fields, const int N, double eps) {
  VP oils;

  rep(i, N) {
    rep(j, N) {
      cout << "q 1 " << i << ' ' << j << endl;

      int resp;
      cin >> resp;

      if (resp != 0) {
        oils.push_back(P(i, j));
      }
    }
  }

  return oils;
}

void output(const VP& oils) {
  int n = (int)oils.size();
  cout << 'a' << ' ' << n << ' ';
  rep(i, n) {
    cout << oils[i].i << ' ' << oils[i].j;
    if (i != n - 1) cout << ' ';
  }
  cout << endl;
}

int main() {
  int N, M;
  double eps;
  cin >> N >> M >> eps;

  VVP fields = get_fields(M);
  VP oils = solver(fields, N, eps);
  output(oils);
}
