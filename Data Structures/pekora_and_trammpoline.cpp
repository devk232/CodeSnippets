#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n], d[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		d[0] = a[0];
		int ans = 0;
		for(int i = 1; i < n; i++)
			d[i] = a[i] - a[i - 1];
		for(int i = 0;i < n; i++) {
			ans += max(a[i] - 1, 0);z
			a[0] = d[0];
			for(int i = 1; i < n; i++)
				a[i] = d[i] + a[i - 1];
		}

	}
	return 0;
}