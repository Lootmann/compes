#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int c{}, w{};
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == 'c') c++;
    if (s[i] == 'w') w++;
  }

  if (c <= w) {
    cout << (c - 1) << endl;
  } else {
    cout << w << endl;
  }
}
