#include <iostream>
using namespace std;

long long int add(long long int a, long long int b) {
  while (b != 0) {
    int carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return a;
}

int main() {
  long long int a, b;
  cin >> a >> b;
  cout << add(a, b) << endl;
}
