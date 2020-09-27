#include <bits/stdc++.h>
using namespace std;

int Bfs(int n, vector<pair<int, int>> adj[], int node){
    int pre[n + 1], dis[n + 1];
    deque<int> dq;
    dq.push_back(node);
     for(int i = 1; i < n + 1; i++)
      dis[i] = 1e8;
    memset(pre, -1, sizeof(pre));
    dis[node] = 0;
    while(!dq.empty()){
        int vertex = dq.front();
        dq.pop_front();
        for(auto i: adj[vertex]){
           if(i.second + dis[vertex] < dis[i.first]){
               pre[i.first] = vertex;
               dis[i.first] = i.second + dis[vertex];
               if(i.second == 1){
                  dq.push_back(i.first);
               }
               else{
                 dq.push_front(i.first);
               }
           }
        }
    }
    return dis[n];
}
int main(){
    int n;                       
    int m;                     
    cin >> n >> m;
    int x, y, len;
    vector<pair<int, int>> v[n + 1];          
    for(int i = 0; i < m; i++){
        cin >> x >> y >> len;
        v[x].push_back({y, len});
        v[y].push_back({x, len});
    }
    int node = 1;               
    Bfs(n, v, node);
}
