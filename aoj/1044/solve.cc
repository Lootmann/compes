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

vector<string> split(const string& word) {
  bool is_camel{false};
  int n = (int)word.size();

  rep(i, n) {
    if (word[i] == '_') is_camel = true;
  }

  vector<string> res;

  // split underscore
  if (is_camel) {
    int idx{};
    rep(i, n) {
      if (word[i] == '_') {
        res.push_back(word.substr(idx, i - idx));
        idx = i + 1;
      }
    }

    res.push_back(word.substr(idx));
    return res;
  }

  // split Upper and Lowercase
  int idx{};
  for (int i = 1; i < n; ++i) {
    if ('A' <= word[i] && word[i] <= 'Z') {
      res.push_back(word.substr(idx, i - idx));
      idx = i;
    }
  }
  res.push_back(word.substr(idx));
  return res;
}

string Title(const string s) {
  string res{s};
  transform(res.begin(), res.end(), res.begin(), ::tolower);
  res[0] = toupper(res[0]);
  return res;
}

string Lower(const string s) {
  string res{s};
  transform(res.begin(), res.end(), res.begin(), ::tolower);
  return res;
}

string conv(const vector<string>& words, const string& nametype) {
  string ans{};
  int n = (int)words.size();

  if (nametype == "L") {
    rep(i, n) {
      if (i == 0) {
        ans += Lower(words[i]);
      } else {
        ans += Title(words[i]);
      }
    }
  } else if (nametype == "U") {
    rep(i, n) {
      ans += Title(words[i]);
    }
  } else {
    rep(i, n) {
      // underscore
      string word = Lower(words[i]);
      if (i == 0) {
        ans += word;
      } else {
        ans += "_" + word;
      }
    }
  }

  return ans;
}

void solve(const string& word, const string& nametype) {
  auto res = split(word);
  auto ans = conv(res, nametype);
  output(ans);
}

int main() {
  FastIO;
  string word, nametype;
  while (cin >> word >> nametype) {
    if (word == "EndOfInput" && nametype == "X") return 0;
    solve(word, nametype);
  }
}
