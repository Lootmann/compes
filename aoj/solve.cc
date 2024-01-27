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
  int* m_array;
  int m_idx;
  int m_size;

  vector() : m_idx{0}, m_size(10) { m_array = new int[m_size]; }
  vector(int size_) : m_idx{0}, m_size(size_) { m_array = new int[size_]; }
  ~vector() { delete[] m_array; }

  void pushBack(int num) {
    if (m_idx >= m_size) resize();
    m_array[m_idx] = num;
    m_idx++;
  }

  void resize() {
    int* tmp = new int[m_size * 2];
    for (int i = 0; i < m_size; ++i) {
      tmp[i] = m_array[i];
    }
    m_size *= 2;
    m_array = tmp;
  }

  void dumps() {
    if (m_idx == 0) {
      cout << '\n';
      return;
    }

    for (int i = 0; i < m_idx; ++i) {
      cout << m_array[i] << (i == m_idx - 1 ? '\n' : ' ');
    }
  }

  void clear() {
    m_array = new int[m_size];
    m_idx = 0;
  }
};

struct vector2 {
  int m_size;
  me::vector* vectors;
  vector2(int size) : m_size(size) { vectors = new vector[size]; }
  ~vector2() { delete[] vectors; }

  void pushBack(int t, int x) { vectors[t].pushBack(x); }
  void dumps(int t) { vectors[t].dumps(); }
  void clear(int t) { vectors[t].clear(); }
};

};  // namespace me

int main() {
  FastIO;

  int n, q;
  cin >> n >> q;

  me::vector2 v(n);

  rep(_, q) {
    int op;
    cin >> op;

    if (op == 0) {
      int t, x;
      cin >> t >> x;
      v.pushBack(t, x);
    } else if (op == 1) {
      int t;
      cin >> t;
      v.dumps(t);
    } else {
      int t;
      cin >> t;
      v.clear(t);
    }
  }
}
