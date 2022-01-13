#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> sieve(ll n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (ll i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (ll j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<ll> prime_numbers;
  for (ll i = 1; i <= n; i++)
    if (prime[i])
      prime_numbers.push_back(i);
  return prime_numbers;
}

int main() { sieve(100); }