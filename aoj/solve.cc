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

struct Card {
  string mark;
  int num;
};

void BubbleSort(vector<Card>& src) {
  for (size_t i = 0; i < src.size(); i++) {
    for (size_t j = src.size() - 1; j > i; --j) {
      if (src.at(j).num < src.at(j - 1).num) {
        Card temp = src.at(j);
        src.at(j) = src.at(j - 1);
        src.at(j - 1) = temp;
      }
    }
  }
}

void SelectionSort(vector<Card>& src) {
  for (size_t i = 0; i <= src.size() - 1; i++) {
    size_t minj = i;
    for (size_t j = i; j <= src.size() - 1; j++) {
      if (src.at(j).num < src.at(minj).num) {
        minj = j;
      }
    }
    Card temp = src.at(i);
    src.at(i) = src.at(minj);
    src.at(minj) = temp;
  }
}

auto trace = [](vector<struct Card> vi) {
  for (size_t i = 0; i < vi.size(); i++) {
    cout << vi.at(i).mark << vi.at(i).num;
    cout << ((i != vi.size() - 1) ? " " : "\n");
  }
};

auto is_stable = [](vector<struct Card> v1, vector<struct Card> v2) {
  for (size_t i = 0; i < v1.size(); i++) {
    if (v1.at(i).mark != v2.at(i).mark) {
      return false;
    }
  }
  return true;
};

int main() {
  vector<Card> for_bubble;
  vector<Card> for_selection;

  int n;
  cin >> n;
  while (n--) {
    string input;
    cin >> input;

    Card card;
    card.mark = input[0];
    card.num = input[1] - '0';

    for_bubble.push_back(card);
    for_selection.push_back(card);
  }

  BubbleSort(for_bubble);
  SelectionSort(for_selection);

  trace(for_bubble);
  cout << "Stable" << endl;

  trace(for_selection);
  if (is_stable(for_bubble, for_selection)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
}
