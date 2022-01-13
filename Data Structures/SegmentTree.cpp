#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> tree, a;

// prameters => lower bound, upper bound, tree pointer(initial = 1)
void build(int l, int r, int v) {
  if (l == r) {
    tree[v] = a[l];
  } else {
    int mid = (l + r) / 2;
    build(l, mid, 2 * v);
    build(mid + 1, r, 2 * v + 1);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
  }
}

// parameters => tree pointer(initial = 1), lower bound(initial 0), upper
// bound(initial n-1), postion to update, new value
void update(int v, int l, int r, int pos, int new_val) {
  if (l == r) {
    tree[v] = new_val;
  } else {
    int mid = (l + r) / 2;
    if (pos <= mid)
      update(2 * v, l, mid, pos, new_val);
    else
      update(2 * v + 1, mid + 1, r, pos, new_val);
    tree[v] = min(tree[2 * v], tree[2 * v + 1]);
  }
}
// paramenters =>  tree pointer(initial = 1),  lower bound(initial 0), upper
// bound(initial n-1), lower bound range, upper bound range,
int query(int v, int q1, int q2, int l, int r) {
  if (l > r)
    return 1e10;
  if (l == q1 && r == q2)
    return tree[v];
  int mid = (q1 + q2) / 2;
  return min(query(v * 2, q1, mid, l, min(r, mid)),
             query(v * 2 + 1, mid + 1, q2, max(l, mid + 1), r));
}

signed main() {
  cin >> n >> q;
  tree.resize(4 * n + 1);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, n - 1, 1);
  while (q--) {
    int aa, b, c;
    cin >> aa >> b >> c;
    if (aa == 1)
      update(1, 0, n - 1, b - 1, c);
    else
      cout << query(1, 0, n - 1, b - 1, c - 1) << endl;
  }
  return 0;
}

// problem => https://cses.fi/problemset/task/1649