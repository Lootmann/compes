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
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
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

bool is_good_suite(char suite) {
  set<char> suites{'H', 'D', 'C', 'S'};
  return suites.find(suite) != suites.end();
}
bool is_good_number(char number) {
  set<char> nums{'A', '2', '3', '4', '5', '6', '7',
                 '8', '9', 'T', 'J', 'Q', 'K'};
  return nums.find(number) != nums.end();
}

int main() {
  int n;
  cin >> n;

  set<string> cards;
  bool is_good{true};
  rep(_, n) {
    string card;
    cin >> card;

    cards.insert(card);

    char suite = card[0];
    char number = card[1];

    if (!is_good_suite(suite)) {
      is_good = false;
    }

    if (!is_good_number(number)) {
      is_good = false;
    }
  }

  if ((int)cards.size() != n) die("No");

  if (is_good)
    cout << "Yes" << el;
  else
    cout << "No" << el;
}
