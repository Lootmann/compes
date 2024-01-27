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

namespace me {
struct vector {
  int* array;
  int idx;
  int size;

  vector() : idx(0), size(10) {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
      array[i] = 0;
    }
  }

  vector(int size_) : idx(0), size(size_) {
    array = new int[size_];
    for (int i = 0; i < size_; ++i) {
      array[i] = 0;
    }
  }
  ~vector() { delete[] array; }

  void pushBack(int x) {
    if (size <= idx) {
      resize();
    }

    array[idx++] = x;
  }

  int randomAccess(int p) {
    assert(size >= p);
    return array[p];
  }

  bool popBack() {
    idx--;
    return true;
  }

  bool resize() {
    size *= 2;
    int* tmp = new int[size];
    for (int i = 0; i < idx; ++i) {
      tmp[i] = array[i];
    }
    array = tmp;
    return true;
  }
};
};  // namespace me

int main() {
  FastIO;
  int n;
  cin >> n;

  me::vector v(n);
  rep(_, n) {
    int query;
    cin >> query;

    if (query == 0) {
      int x;
      cin >> x;
      v.pushBack(x);
    } else if (query == 1) {
      int p;
      cin >> p;
      output(v.randomAccess(p));
    } else {
      v.popBack();
    }
  }
}
