#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
char a[1001][1001];
bool visited[1001][1001];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
vector<vector<pair<int,int>>> pre(1001, vector<pair<int,int>>(1001,{-1, -1}));
vector<vector<char>> ch(1001, vector<char>(1001, '-'));
string ans, abc = "RDUL";

void bfs(int x, int y){
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int ax = q.front().first, b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(a[ax + dx[i]][b + dy[i]] == '#' || ax+dx[i] > n-1 || b+dy[i] > m - 1 || ax+dx[i] < 0 || b+dy[i] < 0){
                continue;
            }
            if(!visited[ax + dx[i]][b + dy[i]]){
               visited[ax + dx[i]][b + dy[i]] = true;
               pre[ax + dx[i]][b + dy[i]].first  = ax;
               pre[ax + dx[i]][b + dy[i]].second = b;
               ch[ax + dx[i]][b + dy[i]] = abc[i];
               q.push({ax + dx[i], b + dy[i]});
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.'){
                bfs(i, j);
            }
        }
    }
    return 0;
}