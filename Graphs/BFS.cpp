#include <bits/stdc++.h>
using namespace std;

void BFS(int n,vector<int> v[], int node){
    bool visited[n + 1];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    vector <int> a;
    int distance[n + 1];
    int pre[n + 1];
    distance[node - 1] = 0;
    queue <int> q;
    q.push(node);
    visited[node] = true;
    a.push_back(node);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto i: v[cur]){
            if(!visited[i]){
                visited[i] = true;
                distance[i] = distance[cur] + 1;
                a.push_back(i);
                pre[i] = cur;
                q.push(i);

            }
        }
    }
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;                       // number of nodes
    cin >> n;
    int m;                      // number of vertices
    cin >> m;
    int x, y;
    vector<int> v[n + 1];          // adjacency list
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int node;                 // starting node 
    cin >> node;
    BFS(n, v, node);
}