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

vector<string> get_lines() {
  string tmp;
  cin >> tmp;

  vector<int> pos;
  rep(i, (int)tmp.size()) {
    if (tmp[i] == '"') {
      pos.push_back(i);
    }
  }

  vector<string> res;
  for (int i = 0; i < (int)pos.size() / 2; ++i) {
    string name = tmp.substr(pos[2 * i] + 1, pos[2 * i + 1] - pos[2 * i] - 1);
    res.push_back(name);
  }

  sort(res.begin(), res.end());

  return res;
}

llint count_score(const string& name) {
  llint sum{};
  for (auto ch : name) {
    sum += ch - 'A' + 1;
  }
  return sum;
}

int main() {
  FastIO;

  vector<string> lines = get_lines();

  llint ans{};
  rep(i, (int)lines.size()) {
    ans += (i + 1) * count_score(lines[i]);
  }

  output(ans);
}
