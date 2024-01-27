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

namespace me {
struct Node {
  int m_num;
  Node *m_prev, *m_nxt;
  Node() : m_num(-1), m_prev(nullptr), m_nxt(nullptr) {}
  Node(int num) : m_num(num), m_prev(nullptr), m_nxt(nullptr) {}
  //~Node() {}
};

template <class T> struct Deque {
  Node* m_dummy;
  int m_size;

  Deque() {
    m_dummy = new Node();
    m_dummy->m_nxt = m_dummy;
    m_dummy->m_prev = m_dummy;
  }
  //~Deque() {}

  void insert(T x) {
    m_size++;

    Node* new_node = new Node(x);
    auto old = m_dummy->m_nxt;
    m_dummy->m_nxt = new_node;
    new_node->m_nxt = old;
    old->m_prev = new_node;
    new_node->m_prev = m_dummy;
  }

  void deleteNum(T x) {
    if (is_empty()) return;
    Node* tmp = m_dummy;

    while ((tmp = tmp->m_nxt) != m_dummy) {
      if (tmp->m_num == x) {
        m_size--;
        tmp->m_prev->m_nxt = tmp->m_nxt;
        tmp->m_nxt->m_prev = tmp->m_prev;
        return;
      }
    }
  }

  Node* deleteFirst() {
    m_size--;

    Node* d = m_dummy->m_nxt;
    m_dummy->m_nxt = m_dummy->m_nxt->m_nxt;
    m_dummy->m_nxt->m_prev = m_dummy;
    return d;
  }

  Node* deleteLast() {
    m_size--;

    Node* d = m_dummy->m_prev;
    m_dummy->m_prev = m_dummy->m_prev->m_prev;
    m_dummy->m_prev->m_nxt = m_dummy;
    return d;
  }

  void out() {
    Node* t = m_dummy->m_nxt;

    while (t->m_nxt != m_dummy) {
      cout << t->m_num << ' ';
      t = t->m_nxt;
    }
    cout << t->m_num << '\n';
  }

  bool is_empty() {
    return m_dummy->m_nxt == m_dummy || m_dummy->m_prev == m_dummy;
  }

  // debug
  T top() {
    if (!is_empty()) return m_dummy->m_nxt->m_num;
    throw runtime_error("No Queue");
  }

  int size() const { return m_size; }
};

}  // namespace me

int main() {
  FastIO;
  int n;
  cin >> n;

  me::Deque<int> que;

  rep(_, n) {
    string op;
    cin >> op;

    if (op == "insert") {
      int x;
      cin >> x;
      que.insert(x);
    } else if (op == "delete") {
      int x;
      cin >> x;
      que.deleteNum(x);
    } else if (op == "deleteFirst") {
      que.deleteFirst();
    } else if (op == "deleteLast") {
      que.deleteLast();
    }
  }
  que.out();
}
