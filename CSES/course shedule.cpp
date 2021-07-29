#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
int pre[1000001], color[10000001];
vector<int> v[1000001];
vector<ll> ans;

bool dfs(int x){
    color[x] = 1;
    for(int i: v[x]){
         if(color[i] == 1){
            cout << "IMPOSSIBLE" << endl;
            exit(0);
         }
        else if(!color[i]){
            dfs(i);
        }
    }
    color[x] = 2;
    ans.push_back(x);
   // cout << x << " " << ans.back() << endl;
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
    for(int i = 1; i <= n; i++){
        if(color[i] == 0)
            dfs(i);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[n-1-i] << ' ';
    }
    return 0;
}