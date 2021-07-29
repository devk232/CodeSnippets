#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int visited[2000001], s[2000001];
int n;
 vector<int> v[2000001];
 
void dfs(int x){
    s[x] = 1;
    for(int i : v[x]){
        dfs(i);
        s[x] += s[i];
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a;cin >> a;
        v[a].push_back(i + 2);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << s[i]-1 << ' ';
    }
    return 0;
}