#include <iostream>
using namespace std;
int main() {
  long long int n,i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    long long int a = i * i * (i * i - 1) / 2;
    long long int b = 2 * (i - 2) * (2 * (i - 4) + 6);
    cout << a - b << endl;
  }
  return 0;
}
