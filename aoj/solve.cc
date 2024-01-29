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
using P = pair<int, int>;

tuple<int, int> input(string line) {
  int a, b, idx{};
  rep(i, (int)line.size()) {
    if (line[i] == ',') {
      idx = i;
      break;
    }
  }
  a = stoi(line.substr(0, idx));
  b = stoi(line.substr(idx + 1));
  return tuple(a, b);
}

int main() {
  FastIO;
  int w, n;
  cin >> w >> n;

  vector<P> vertical_lines;

  rep(_, n) {
    string line;
    cin >> line;

    int a, b;
    tie(a, b) = input(line);
    a--, b--;
    vertical_lines.push_back(make_pair(a, b));
  }

  vector<int> ans(w, 0);
  rep(i, w) {
    int rot{i};
    for (auto p : vertical_lines) {
      if (p.first == rot) {
        rot = p.second;
      } else if (p.second == rot) {
        rot = p.first;
      }
    }
    ans[rot] = i + 1;
  }

  for (auto r : ans) {
    output(r);
  }
}
