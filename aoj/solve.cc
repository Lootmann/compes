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

int cnt = 0;

auto trace = [](const vector<int>& v) {
  for (size_t i = 0; i < v.size(); i++) {
    cout << v.at(i);
    cout << ((i != v.size() - 1) ? " " : "\n");
  }
};

void insertionSort(vector<int>& vi, int n, int g) {
  for (int i = g; i < n; i++) {
    int v = vi.at(i);
    int j = i - g;
    while (j >= 0 && vi.at(j) > v) {
      vi.at(j + g) = vi.at(j);
      j = j - g;
      cnt++;
    }
    vi.at(j + g) = v;
  }
}

void shellSort(vector<int>& vi, int n) {
  vector<int> g;
  for (int i = 1;;) {
    if (i > n) break;
    g.push_back(i);
    i = 3 * i + 1;
  }
  reverse(g.rbegin(), g.rend());

  // output m and g
  cout << g.size() << endl;
  trace(g);

  for (auto gi : g) {
    insertionSort(vi, n, gi);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> vi(n);
  rep(i, n) cin >> vi.at(i);

  shellSort(vi, n);
  cout << cnt << endl;
  for (auto num : vi) cout << num << endl;
}
