#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[10000001];
int pre[10000001];

void BFS(vector<int> v[], int node){
    for(int i = 0; i < n; i++)
        visited[i] = false;
    pre[node] = -1;
    vector <int> a;
    int distance[10000001];
    distance[node] = 0;
    queue <int> q;
    q.push(node);
    visited[node] = true;
    a.push_back(node);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i: v[cur]){
            if(!visited[i]){
                visited[i] = true;
                distance[i] = distance[cur] + 1;
               // cout << "joio" << endl;
                a.push_back(i);
                pre[i] = cur;
                q.push(i);
            }
        }
    }
    if(!visited[n]){
        cout << "IMPOSSIBLE" << endl;
    }else{
        vector<int> ans;
        for(int i = n; i != 1; i = pre[i]){
            ans.push_back(pre[i]);
        }
        reverse(ans.begin(),ans.end());
        ans.push_back(n);
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
}

int main(){
    cin >> n >> m;
    vector<int> v[n + 1];  
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS(v,1);
    return 0;
}
