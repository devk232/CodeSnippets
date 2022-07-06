#include <bits/stdc++.h>
using namespace std;

// using BFS
bool bfs(int node, int parent, vector <int> graph[], vector<bool> visited) {
    queue<pair<int,int>> q;
    visited[node] = true;
    q.push({node, -1});
    while (!q.empty()) {
        int vertex = q.front().first, parent =  q.front().second;
        q.pop();
        for (int i: graph[vertex]) {    
            if (!visited[i]) {
                visited[i] = true;
                q.push({i, vertex});
            } else if (i != parent) {
                return false;
            }
        }
    }
    return true;
}

// using DFS
bool dfs(int node, int parent, vector <int> graph[], vector<bool> visited) {
    visited[node] = true;
    for (int v: graph[node]) {
        if (!visited[v]) {
            if (!dfs(v, node, graph, visited)) {
                return false;
            }
        } else if (v != parent) {
            return false;
         }
    }
    return true;
}
