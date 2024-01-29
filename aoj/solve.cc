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

namespace me {
template <typename T> struct Node {
  Node* m_nxt;
  int m_num;
  Node() : m_nxt{nullptr}, m_num{0} {}
  Node(int num) : m_nxt{nullptr}, m_num{num} {}
};

template <typename T> struct Stack {
  Node<T>* m_dummy;
  Stack() { m_dummy = new Node<T>(-1); }
  ~Stack() {
    while (m_dummy->m_nxt != nullptr) {
      Node<T>* tmp = m_dummy->m_nxt;
      m_dummy->m_nxt = m_dummy->m_nxt->m_nxt;
      delete tmp;
    }
    delete m_dummy;
  }

  void push(int num) {
    Node<T>* new_node = new Node<T>(num);

    if (is_empty()) {
      m_dummy->m_nxt = new_node;
    } else {
      new_node->m_nxt = m_dummy->m_nxt;
      m_dummy->m_nxt = new_node;
    }
  }

  T pop() {
    assert(!is_empty());
    Node<T>* pop_node = m_dummy->m_nxt;
    m_dummy->m_nxt = m_dummy->m_nxt->m_nxt;

    int num = pop_node->m_num;
    delete pop_node;
    return num;
  }

  int top() {
    assert(!is_empty());
    return m_dummy->m_nxt->m_num;
  }

  bool is_empty() { return m_dummy->m_nxt == nullptr; }

  void out() {
    Node<T>* tmp = m_dummy->m_nxt;
    while (tmp != nullptr) {
      cerr << "[" << tmp->m_num << "]";
      tmp = tmp->m_nxt;
    }
    cerr << '\n';
  }
};
}  // namespace me

int main() {
  FastIO;
  me::Stack<int> st;

  string s;
  while (cin >> s) {
    if (s == "+") {
      int left = st.pop();
      int right = st.pop();
      st.push(left + right);
    } else if (s == "-") {
      int left = st.pop();
      int right = st.pop();
      st.push(right - left);
    } else if (s == "*") {
      int left = st.pop();
      int right = st.pop();
      st.push(left * right);
    } else {
      st.push(stoi(s));
    }
    st.out();
  }

  // st.out();
  cout << st.top() << '\n';
}
