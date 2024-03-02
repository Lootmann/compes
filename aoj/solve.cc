#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

void maxHeapify(vector<int>& ai, int N, int i) {
  int left = 2 * i;
  int right = 2 * i + 1;
  int largest{};

  if (left <= N && ai[left] > ai[i]) {
    largest = left;
  } else {
    largest = i;
  }

  if (right <= N && ai[right] > ai[largest]) {
    largest = right;
  }

  if (largest != i) {
    int t = ai[i];
    ai[i] = ai[largest];
    ai[largest] = t;
    maxHeapify(ai, N, largest);
  }
}

void buildMaxHeap(vector<int>& ai, const int N) {
  for (int i = N / 2; i >= 1; --i) {
    maxHeapify(ai, N, i);
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> heap(n + 1, 0);
  rep(i, n) cin >> heap[i + 1];

  buildMaxHeap(heap, n);

  rep(i, n) {
    cout << ' ' << heap[i + 1];
  }
  cout << el;
}
