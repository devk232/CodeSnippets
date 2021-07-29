#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int n, m;
bool ok = false;
char a[1001][1001];
int sdis[1001][1001];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
string ans, abc = "RDUL";

void bfs(vector<pair<int,int>> r){
    int dis[1001][1001];
    bool visited[1001][1001];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dis[i][j] = 1e5;
            visited[i][j] = false;
        }
    }
    queue<pair<int,int>> q;
    for(int i = 0; i < r.size(); i++){
        q.push({r[i].first, r[i].second});
        sdis[r[i].first][r[i].second] = 0;
        visited[r[i].first][r[i].second] = 1;
    }
    while(!q.empty()){
        int ax = q.front().first, b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(a[ax + dx[i]][b + dy[i]] == '#' || ax+dx[i] > n-1 || b+dy[i] > m-1 || ax+dx[i] < 0 || b+dy[i] < 0)
                continue;
            if(!visited[ax + dx[i]][b + dy[i]]){
               visited[ax + dx[i]][b + dy[i]] = true;
               sdis[ax + dx[i]][b + dy[i]] = sdis[ax][b] + 1;
               q.push({ax + dx[i], b + dy[i]});
            }
        }
    }
}

void bfs2(int x, int y){
    bool visited[1001][1001];
    vector<vector<pair<int,int>>> pre(1001, vector<pair<int,int>>(1001,{-1, -1}));
    vector<vector<char>> ch(1001, vector<char>(1001, '-'));
    pre[x][y] = make_pair(-1,-1);
    int dis[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dis[i][j] = 1e5;
            visited[i][j] = false;
        }
    }
    visited[x][y] = true;
    dis[x][y] = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int ax = q.front().first, b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(a[ax + dx[i]][b + dy[i]] == '#' || ax+dx[i] > n-1 || b+dy[i] > m - 1 || ax+dx[i] < 0 || b+dy[i] < 0){
                continue;
            }
            if(dis[ax][b] + 1 >= sdis[ax + dx[i]][b + dy[i]])
                continue;
            if(visited[ax + dx[i]][b + dy[i]] == false){
               visited[ax + dx[i]][b + dy[i]] = true;
               dis[ax + dx[i]][b + dy[i]] = dis[ax][b] + 1;
               pre[ax + dx[i]][b + dy[i]].first  = ax;
               pre[ax + dx[i]][b + dy[i]].second = b;
               ch[ax + dx[i]][b + dy[i]] = abc[i];
               q.push({ax + dx[i], b + dy[i]});
            }
        }
    }
   // cout << pre[1][6].first << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0 || j == m -1 || i == n - 1){
                if(visited[i][j] == true){
                    cout << "YES" << endl;
                    int at = i, bt = j;
                    while(at != -1 && bt != -1){
                        //cout << at << " " << bt << endl;
                        ans += ch[at][bt];
                        int x = at;
                        at = pre[at][bt].first;
                        bt = pre[x][bt].second; 
                    }
                     ans.pop_back();
                    reverse(ans.begin(), ans.end());
                    cout << ans.size() << endl;
                    cout << ans << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    for(int T = 0; T < t ; T++){
        cin >> n >> m;
        vector<pair<int,int>> rt;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                sdis[i][j] = 1e5;
                if(a[i][j] == 'M')
                    rt.push_back({i,j});
            }
        }
        bfs(rt);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 'A'){
                    bfs2(i,j);
                    return 0;
                }
            }
        }
    }
    return 0;
}