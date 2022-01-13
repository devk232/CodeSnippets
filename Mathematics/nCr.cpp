#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll mod = 1e9 + 7;
const int N = 1e5 + 1;
ll fact[N], invfact[N];

ll powerM(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans = (ans * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ans;
}

ll invM(ll num) { return powerM(num, mod - 2); }

void precompute() {
  fact[0] = fact[1] = 1;
  for (ll i = 2; i < N; i++)
    fact[i] = (fact[i - 1] * i) % mod;
  invfact[N - 1] = invM(fact[N - 1]);
  for (ll i = N - 2; i >= 0; i--)
    invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}
ll nCr(ll x, ll y) {
  if (y > x)
    return 0;
  else
    return (((fact[x] * invfact[y]) % mod) * invfact[x - y]) % mod;
}
