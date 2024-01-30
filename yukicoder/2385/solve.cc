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
using ullint = unsigned long long int;

int checkType(string s) {
  // decimal
  if (s.size() <= 2) {
    return 0;
  }

  string type = s.substr(0, 2);
  if (type == "0b") {
    return 1;  // binary
  } else if (type == "0o") {
    return 2;  // octal
  } else if (type == "0x") {
    return 3;  // hex
  } else {
    return 0;
  }
}

ullint calc_binary(const string& s) {
  ullint res{};
  for (auto ch : s) {
    res *= 2;
    res += ch == '1';
  }
  return res;
}

ullint calc_octal(const string& s) {
  ullint res{};
  for (auto ch : s.substr(2)) {
    res *= 8;
    res += ch - '0';
  }
  return res;
}

ullint ch2hex(char ch) {
  if ('0' <= ch && ch <= '9') return ch - '0';
  return ch - 'a' + 10;
}
ullint calc_hex(const string& s) {
  ullint res{};
  for (auto ch : s.substr(2)) {
    res *= 16;
    res += ch2hex(ch);
  }

  return res;
}

int main() {
  FastIO;
  int q;
  cin >> q;

  rep(_, q) {
    string s;
    cin >> s;

    switch (checkType(s)) {
      case 0:  // decimal
        output(s);
        break;
      case 1:  // binary
        output(calc_binary(s));
        break;
      case 2:  // octal
        output(calc_octal(s));
        break;
      case 3:  // hex
        output(calc_hex(s));
        break;
      default:
        throw runtime_error(":^)");
    }
  }
}
