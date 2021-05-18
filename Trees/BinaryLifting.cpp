#include <bits/stdc++.h>
using namespace std;

int n, LOG = 20;
vector<int> v[100001];
vector<int> depth(100001);

void precompute (vector<int> parent) {
    parent[0] = 0;
    for (int i = 0; i < n; i++) {
        if(i) depth[i] = depth[parent[i]] + 1;
        v[i][0] = parent[i];
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            v[i][j] = v[v[i][j - 1]][j - 1];  
        }
    }
}

int findAncestor (int node, int k) {
    if (depth[node] < k)
        return -1;
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) 
            node = v[node][i]; 
    }
    return node;
}