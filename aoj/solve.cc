#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; (int)i < n; ++i)
#define output(msg) cout << (msg) << '\n'
#define die(msg)         \
  do {                   \
    cout << msg << endl; \
    exit(0);             \
  } while (0)
#define INFi 1 << 30
#define INFll 1LL << 60

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;
using T = tuple<int, int, char, llint, string>;

bool compare(const T& l, const T& r) {
  if (get<0>(l) == get<0>(r)) {
    if (get<1>(l) == get<1>(r)) {
      if (get<2>(l) == get<2>(r)) {
        if (get<3>(l) == get<3>(r)) {
          return get<4>(l) < get<4>(r);
        }
        return get<3>(l) < get<3>(r);
      }
      return get<2>(l) < get<2>(r);
    }
    return get<1>(l) < get<1>(r);
  }
  return get<0>(l) < get<0>(r);
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<T> vt(n);

  rep(i, n) {
    int value, weight;
    char id;
    llint date;
    string name;
    cin >> value >> weight >> id >> date >> name;
    vt[i] = tuple(value, weight, id, date, name);
  }

  sort(vt.begin(), vt.end(), compare);

  rep(i, n) {
    auto item = vt[i];
    cout << get<0>(item) << ' ' << get<1>(item) << ' ' << get<2>(item) << ' '
         << get<3>(item) << ' ' << get<4>(item) << '\n';
  }
}
