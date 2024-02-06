#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

#define FastIO cin.tie(nullptr), ios_base::sync_with_stdio(false);
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define out(msg) cout << (msg) << '\n'
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

struct Brace {
  int left;
  int right;
};

int main() {
  FastIO;
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<Brace> braces;
  stack<int> st;

  rep(i, n) {
    char b = s[i];
    if (b == '(') {
      st.push(i + 1);
    } else {
      int left = st.top();
      st.pop();
      int right = i + 1;
      braces.push_back(Brace{left, right});
    }
  }

  dump(st.size());

  for (auto b : braces) {
    if (b.left == k) die(b.right);
    if (b.right == k) die(b.left);
  }
}
