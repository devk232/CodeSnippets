vector<int> kahn(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    vector<int> g[v];
    vector<int> indegree(v, 0); 
    for (int i = 0; i < e; i++) {
        g[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    for (int i = 0; i < v; i++) 
        if (!indegree[i]) 
            q.push(i);
   while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push_back(x);
       for (int i: g[x]) {
           indegree[i]--;
           if (!indegree[i])
                 q.push(i);
       }
   }
    return ans;
}
