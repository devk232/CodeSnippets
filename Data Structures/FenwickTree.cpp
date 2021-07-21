#include <bits/stdc++.h>
using namespace std;
#define int long long 


int n, q;
vector<int> tree;

void add (int k, int r) {
  while (k <= n) {
    tree[k] += r;
    k += k & (-k);
  }
}

// returns sum(1, k)
int sum (int k) {
  int s = 0;
  while (k >= 1) {
    s +=  tree[k];
    k -= k & (-k);
  }
  return s;
}


signed main() {
  cin >> n >> q;
  tree.assign(n + 1, 0);
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(i, a[i]);
  }
  while (q--) {
    int aa, b, c;
    cin >> aa >> b >> c;
    if (aa == 1) {
      add(b, c - a[b]);
      a[b] = c;
    } else {
      cout <<  sum(c) - sum(b - 1) << endl;
    }
  }
} 
 
// problem - https://cses.fi/problemset/task/1648/