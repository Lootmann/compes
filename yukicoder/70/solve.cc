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

int time2int(string s) {
  int idx = s.find(":");
  int h = stoi(s.substr(0, idx)) * 60;
  int m = stoi(s.substr(idx + 1));
  int sum = h + m;
  return sum;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  int sum{};

  rep(_, n) {
    string a, b;
    cin >> a >> b;

    int left = time2int(a);
    int right = time2int(b);

    if (left > right) {
      right += 24 * 60;
    }
    sum += right - left;
    dump(sum, left, right, right - left);
  }

  output(sum);
}
