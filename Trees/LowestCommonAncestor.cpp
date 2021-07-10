#include <bits/stdc++.h>
using namespace std;

int n, LOG = 20;
vector<int> v[100001];
vector<int> depth(100001);


int getLCA (int node1, int node2) {
    if (depth[node1] < depth[node2]) {
        swap(node1, node2);
    }
    int k = depth[node1] - depth[node2];
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            node1 = v[node1][i];
        }
    }
    if (node1 == node2) 
        return node1;
    for (int i = LOG - 1; i >= 0; i--) {
        if (v[node1][i] != v[node2][i]) {
            node1 = v[node1][i];
            node2 = v[node2][i];
        }
    }
    node1 = v[node1][0];
    return node1;
}