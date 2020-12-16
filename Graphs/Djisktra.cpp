
#include <bits/stdc++.h>
using namespace std;

void Djikstra(int n, vector<pair<int, int>> adj[], int node)
{
    int dis[n + 1], pre[n + 1];
    bool visited[n + 1];
    memset(pre, -1, sizeof(pre));
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < n + 1; i++)
        dis[i] = 1e8;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[node] = 0;
    pq.push({0, node});
    int v = node;
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if (dist != dis[vertex])
            continue;
        for (auto j : adj[vertex])
        {
            if (j.second + dis[vertex] < dis[j.first])
            {
                dis[j.first] = j.second + dis[vertex];
                pre[j.first] = vertex;
                pq.push({dis[j.first], j.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int x, y, len;
    vector<pair<int, int>> v[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> len;
        v[x].push_back({y, len});
        v[y].push_back({x, len});
    }
    int node = 1;
    Djikstra(n, v, node);
}
