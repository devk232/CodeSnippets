#include <bits/stdc++.h>
using namespace std;

int check[1000001];
// if vertex is not visited, then check[i] = 0, if visited but not exited, check[i] = 1, else check[i] = 2
bool DFS(int n, vector<int> v[], int node){
    check[node] = 1;
    for(auto i: v[node]){
        if(check[i] == 1){
            return true;
        }
        if(check[i] == 0 && DFS(n,v,i)){
           return true;
        }
    }
    check[node] = 2;
    return false;
}
bool cycle(vector<int> v[], int n){
    for(int i = 0; i < n; i++){
        if(DFS(n, v, i + 1))
            return true;
    }
    return false;
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
       // v[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
        check[i] = 0;
    }
    int node;                 // starting node 
    cin >> node;
    cout << cycle(v, n) << endl;
}   