#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

void dfs(int x, int y){
    if(a[x][y] == '#' || x > n-1 || y > m - 1 || x < 0 || y < 0)
        return;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        if(!visited[x + dx[i]][y + dy[i]]){
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    for(int T = 0; T < t ; T++){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                visited[i][j] = false;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && a[i][j] == '.'){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}