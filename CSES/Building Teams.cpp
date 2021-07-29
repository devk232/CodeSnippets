#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
bool visited[1000001];
vector<int> v[1000001], c(1000001);

void dfs(int x, int ok){
    visited[x] = true;
    if(ok)
        c[x] = 1;
    else
        c[x] = 2;
    for(int i: v[x]){
        if(!visited[i]){
            dfs(i, 1 - ok);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> in(m), o(m);
    for(int i = 0; i < m; i++){
        cin >> in[i] >> o[i];
        v[in[i]].push_back(o[i]);
        v[o[i]].push_back(in[i]);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i + 1]){
            dfs(i + 1, 1);
        }
    }
    bool ok = true;
    for(int i = 0; i < m; i++){
        if(c[in[i]] == c[o[i]]){
            ok = false;
            break;
        }
    }
    if(ok == false)
        cout << "IMPOSSIBLE" << endl;
    else{
        for(int i = 1; i <= n; i++)
            cout << c[i] << " ";
    }
    return 0;
}