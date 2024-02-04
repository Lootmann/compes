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

vector<llint> remove_duplicate(const vector<llint>& ai) {
  set<llint> st;
  for (auto a : ai) {
    st.insert(a);
  }
  vector<llint> remove_dup;
  for (auto key : st) {
    remove_dup.push_back(key);
  }
  sort(remove_dup.rbegin(), remove_dup.rend());
  return remove_dup;
}

vector<llint> gen_acc(const vector<llint>& bi, map<llint, int>& mp) {
  vector<llint> acc;
  llint sum{};

  for (auto num : bi) {
    for (llint i = 0; i < mp[num]; ++i) {
      sum += num;
    }
    acc.push_back(sum);
  }

  sort(acc.begin(), acc.end());
  acc.pop_back();
  acc.push_back(0);
  return acc;
}

int main() {
  FastIO;
  int n;
  cin >> n;

  vector<llint> ai(n);
  map<llint, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    ai[i] = a;
    mp[a]++;
  }

  vector<llint> bi = remove_duplicate(ai);
  vector<llint> acc = gen_acc(bi, mp);

  int first = bi.front();
  bi.erase(bi.begin());
  bi.push_back(first);
  map<int, int> is;

  rep(i, (int)bi.size()) {
    is[bi[i]] = i;
  }

  rep(i, n) {
    cout << acc[is[ai[i]]] << (i == n - 1 ? '\n' : ' ');
  }
}
