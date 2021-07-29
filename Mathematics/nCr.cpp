#include <bits/stdc++.h>
using namespace std;

int fact[N] , invfact[N];

int powerM(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % mod;
		b /= 2; a = (a * a) % mod;
	} return ans;
}
int invM(int num) {
	return powerM(num, mod - 2);
}

void precompute() {
	fact[0] = fact[1] = 1;
	for (int i = 2; i < N; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	invfact[N - 1] = invM(fact[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		invfact[i] = invfact[i + 1] * (i + 1);
		invfact[i] %= mod;
	}
}

int nCr(int x, int y) {
	if (y > x) return 0;
	int num = fact[x];
	num *= invfact[y]; num %= mod;
	num *= invfact[x - y];
	num %= mod; return num;
}