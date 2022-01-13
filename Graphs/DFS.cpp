#include <bits/stdc++.h>
using namespace std;

bool visited[1000001], order[1000001];

void DFS(int n, vector<int> v[], int node) {
  stack<int> st;
  st.push(node);
  visited[node] = true;
  int k = 1;
  while (k < n) {
    int top = st.top();
    bool t = true;
    for (int i = 0; i < v[top - 1].size(); i++) {
      if (!visited[v[top][i]]) {
        cout << v[top][i] << " ";
        st.push(v[top][i]);
        visited[v[top][i]] = true;
        k++;
        t = false;
        break;
      }
    }
    if (t == true)
      st.pop();
  }
}

void DFSrec(int n, vector<int> v[], int node) {
  visited[node] = true;
  for (auto i : v[node]) {
    if (!visited[i]) {
      cout << i << " ";
      DFSrec(n, v, i);
    }
  }
}

int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  int x, y;
  vector<int> v[n + 1];
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int node;
  cin >> node;
  DFS(n, v, node);
}