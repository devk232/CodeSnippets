#include <bits/stdc++.h>
using namespace std;

// Range Queries for min, max, gcd in a range in O(N*log(N) + Q)
int LOG = 20;
int x[100001][20];
int blog2[100001];

int main() {
  int n, q;
  cin >> n >> q;
  int a[n];
  blog2[1] = 0;
  for (int i = 2; i <= n; i++) {
    blog2[i] = blog2[i/2] + 1;
  }
  LOG = blog2[n] + 1;
  int x[n][LOG];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x[i][0] = a[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      x[i][j] = min (x[i][j - 1], x[i + (1 <<(j - 1))][j - 1]);
    }
  }

  while (q --) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    int length = r - l + 1;
    int k = blog2[length];
    cout << min(x[l][k], x[r - (1 << k) + 1][k]) << endl;
  }
  return 0;
} 