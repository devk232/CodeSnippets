#include <bits/stdc++.h>
using namespace std;


struct DSU {
  int connected;  // no of components
  vector<int> parent, size; // stores parent and size of component ith node belong to.
  void init (int n) {
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = 1;
      size[i] = 1;
    }
    connected = n;
  }
  void union_set(int a, int b) {
    int s1 = find_set(a), s2 = find_set(b);
    if (a == b) return;
    connected--;
    if (size[s1] > size[s2])
      swap(s1, s2);
    size[s2] += size[s1];
    size[s1] = 0;
    parent[s1] = parent[s2];
  }
  int find_set(int node) {
    while (node != parent[node]) {
      parent[node] = parent[parent[node]];
      node = parent[node];
    }
    return node;
  }
};
