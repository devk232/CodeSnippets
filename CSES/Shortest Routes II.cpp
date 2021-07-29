#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    long long dis[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
                dis[i][j] = 1e14;
    for(int i = 0; i < m; i++){
        long long  ax, b, c;
        cin >> ax >> b >> c;
        dis[ax - 1][b - 1] = min(c,dis[ax - 1][b - 1]);
        dis[b - 1][ax - 1] = min(c,dis[b - 1][ax - 1]);
    }
    for(int i = 0; i < n; i++)
        dis[i][i] = 0;
    for(long long k = 0; k < n; k++){
        for(long long  i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(dis[i][k] < 1e14 && dis[k][j] < 1e14 && dis[i][j] != 0)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for(int i = 0; i < q; i++){
        int ax, b;
        cin >> ax >> b;
        if(dis[ax - 1][b - 1] == 1e14)
            cout << -1 << "\n";
        else
            cout << dis[ax - 1][b - 1] << "\n";
    }
    return 0;
}