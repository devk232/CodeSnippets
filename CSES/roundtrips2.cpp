#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
int pre[1000001], color[10000001];
vector<int> v[1000001];
bool dfs(int x){
    color[x] = 1;
    for(int i: v[x]){
         if(color[i] == 1){
            vector<int> ans ={x};
            while(x^i){
                x = pre[x];
                ans.push_back(x);
            }
            ans.push_back(ans[0]);
            reverse(ans.begin(), ans.end());
            cout << ans.size()<< endl;
            for(int i = 0; i < ans.size(); i++)
                cout << ans[i] << ' ';
            exit(0);
         }
        else if(!color[i]){
            pre[i] = x;
            dfs(i);
        }
    }
    color[x] = 2;
    
}


signed main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 0; i <= n; i++)
        color[i] = 0;
    for(int i = 0; i < n; i++){
        if(!color[i]){
            dfs(i + 1);
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}