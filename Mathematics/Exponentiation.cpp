#include <iostream>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;

long long expo(ll a, ll b) {
  if (b == 0)
    return 1;
  int x = expo(a, b / 2) % mod;
  if (b % 2 == 0) {
    return (x * x) % mod;
  } else {
    return (a * expo(a, b - 1)) % mod;
  }
}

// this function returns a^b in log(b) time complexity
ll power(int a, int b, int mod = 1e9 + 7) {
  ll ans = 1;
  while (b) {
    if (b % 2)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}

int main() { cout << power(2, 10) << endl; }
