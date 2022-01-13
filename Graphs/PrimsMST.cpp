#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> v[100000];
bool visited[100001];
int dis[100001], pre[100001];
vector<int> tree;

void findMST() {
  int min_cost = 0;
  for (int i = 1; i <= n; i++)
    dis[i] = 1e6;
  int node = 1;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>> pq;
  dis[node] = 1;
  pq.push({0, node});
  while (!pq.empty()) {
    int dist = pq.top().first;
    int vertex = pq.top().second;
    visited[vertex] = true;
    pq.pop();
    min_cost += dist;
    if (dist != dis[vertex])
      continue;
    for (auto j : v[vertex]) {
      if (!visited[j.first]) {
        if (dis[j.first] > j.second) {
          dis[j.first] = j.second;
          pq.push({dis[j.first], j.first});
          pre[j.first] = vertex;
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, len;
    cin >> x >> y >> len;
    v[x].push_back({y, len});
    v[y].push_back({x, len});
  }
  findMST();
  return 0;
}