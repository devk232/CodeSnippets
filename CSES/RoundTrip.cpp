#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
bool visited[1000001];
int pre[1000001];
vector<int> v[1000001];
bool ok = false;
bool dfs(int x, int y){
  //  cout << x << endl;
    visited[x] = true;
    pre[x] = y;
    for(int i: v[x]){
         if(visited[i] == true && pre[x]!= i){
            if(ok == true)
                return true;
            vector<int> ans;
            ok = true;
            ans.push_back(i);
            for(int k = x; k != i; k = pre[k]){
                ans.push_back(k);
            }
            ans.push_back(i);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
            return true;
        }
        if(!visited[i]){
            dfs(i, x);
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i <= n; i++)
        visited[i] = false;
    for(int i = 0; i < n; i++){
        if(!visited[i + 1]){
            if(dfs(i + 1, -1)){
                break;
            }
        }
    }
    if(ok == false)
        cout << "IMPOSSIBLE" << endl;
    
    return 0;
}