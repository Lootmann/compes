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

void split_sum(vector<int>& vs, int& total, int left, int right) {
  if (left >= right) return;

  int max_num{INFi};
  for (int i = left; i < right; ++i) {
    chmin(max_num, vs[i]);
  }

  total += max_num;
  for (int i = left; i < right; ++i) {
    vs[i] -= max_num;
  }

  vector<int> zeroes;
  zeroes.push_back(-1);
  for (int i = left; i < right; ++i) {
    if (vs[i] == 0) {
      zeroes.push_back(i);
    }
  }

  zeroes.push_back(right);
  int n = (int)zeroes.size();
  for (int i = 0; i < n - 1; ++i) {
    split_sum(vs, total, zeroes[i] + 1, zeroes[i + 1]);
  }
}

int main() {
  FastIO;
  int N;
  cin >> N;

  vector<int> hi(N);
  rep(i, N) cin >> hi[i];

  int total{};
  split_sum(hi, total, 0, N);
  output(total);
}
