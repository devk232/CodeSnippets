
#include <bits/stdc++.h>
using namespace std;

void Djikstra(long long n, vector<pair<long long, long long>> adj[], long long node)
{
   long long dis[n + 1], pre[n + 1];
   bool visited[n + 1];
   memset(pre, -1, sizeof(pre));
   memset(visited, false, sizeof(visited));
   for(long long i = 1; i < n + 1; i++)
      dis[i] = 1e15;
   priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
   dis[node] = 0;
   pq.push({0, node});
   long long v = node; 
   while(!pq.empty()){
      long long dist = pq.top().first;
      long long vertex = pq.top().second;
      pq.pop();
      if(dist != dis[vertex])
        continue;
      for(auto j : adj[vertex]){
          if(j.second + dis[vertex] < dis[j.first]){
                dis[j.first] = j.second + dis[vertex];
                pre[j.first] = vertex;
                pq.push({dis[j.first], j.first});
          }
      }
   }
   for(long long i = 1; i <= n; i++)
      cout << dis[i] << " ";
}

int main()
{
    long long n;                       
    long long m;                     
    cin >> n >> m;
    long long x, y, len;
    vector<pair<long long, long long>> v[n + 1];          
    for(long long i = 0; i < m; i++)
    {
        cin >> x >> y >> len;
        v[x].push_back({y, len});
    }
    long long node = 1;               
    Djikstra(n, v, node);
}
