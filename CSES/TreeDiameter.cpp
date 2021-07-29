// #include <bits/stdc++.h>
// #define ll long long 
// using namespace std;

// int n, dis[2000001], visited[2000001];
// vector<int> v[2000001];

// void bfs(int node){
//     for(int i = 1; i <= n; i++){
//         dis[i] = 1e5;
//         visited[i] = 0;
//     }
//     dis[node] = 0;visited[node] = 1;
//     queue <int> q;
//     q.push(node);
//     while(!q.empty()){
//         int cur = q.front();
//         q.pop();
//         for(int i: v[cur]){
//             if(!visited[i]){
//                 visited[i] = 1;
//                 dis[i] = dis[cur] + 1;
//                 q.push(i);
//             }
//         }
//     }
// }
// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >> n;
//     for(int i = 0; i < n - 1; i++){
//         int a, b;
//         cin >> a >> b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
//     bfs(1);
//     int maxdis = 0, id  = 1;
//     for(int i = 1; i <= n; i++){
//         if(dis[i] > maxdis){
//             id = i;
//             maxdis = dis[i];
//         }
//     }
//     bfs(id);
//     for(int i = 1; i <= n; i++)
//         maxdis = max(dis[i], maxdis);
//     cout << maxdis << endl;
//     return 0;
// }





