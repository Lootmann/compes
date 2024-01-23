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

template <typename T> bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T> bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint = long long int;

random_device rd;
mt19937 gen(rd());

int randint() {
  uniform_int_distribution dist(0, 2);
  return dist(gen);
}

void swap_vi(vector<int>& vi) {
  int l{}, r{};
  while (l == r) {
    l = randint();
    r = randint();
  }

  int tmp = vi[l];
  vi[l] = vi[r];
  vi[r] = tmp;
}

void test(vector<int>& vi) {
  dump("swap");
  // 10 times randamly swap
  rep(i, 10) swap_vi(vi);
  dump(vi[0], vi[1], vi[2]);
}

// 1 2 3
// 2 3 1
// 3 1 2

int main() {
  FastIO;

  // vector<int> vi{1, 2, 3};
  // rep(i, 10) test(vi);

  char s1, s2, s3;
  char t1, t2, t3;

  cin >> s1 >> s2 >> s3;
  cin >> t1 >> t2 >> t3;

  /*
    s1 s2 s3
    s3 s1 s2
    s2 s3 s1

    t1 t2 t3
  */

  bool can_swap = false;
  can_swap |= (t1 == s1 && t2 == s2 && t3 == s3);
  can_swap |= (t1 == s2 && t2 == s3 && t3 == s1);
  can_swap |= (t1 == s3 && t2 == s1 && t3 == s2);
  if (can_swap)
    output("Yes");
  else
    output("No");
}
