#include <bits/stdc++.h>
using namespace std;

void BFS(int n,vector<int> v[], int node){
    bool visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    vector <int> a;
    int distance[n];
    distance[node - 1] = 0;
    queue <int> q;
    q.push(node);
    visited[node - 1] = true;
    a.push_back(node);
    while(!q.empty()){
        for(int i = 0; i < v[q.front() - 1].size(); i++){
            if(!visited[v[q.front() - 1][i] - 1]){
                q.push(v[q.front()- 1][i]);           
                distance[v[q.front()- 1][i] - 1] = distance[q.front() - 1] + 1;
                visited[v[q.front()- 1][i]- 1] = true; 
                a.push_back(v[q.front()- 1][i]);
            }
        }
        q.pop();
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
    vector<int> v[n];          // adjacency list
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        v[x - 1].push_back(y);
        v[y - 1].push_back(x);
    }
    int node;                 // starting node 
    cin >> node;
    BFS(n, v, node);
}