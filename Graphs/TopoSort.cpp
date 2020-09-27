#include <bits/stdc++.h>
using namespace std;

bool visited[1000001];
vector<int> ans;

void DFSrec(int n, vector<int> v[], int node){
    visited[node] = true;
    for(auto i: v[node]){
        if(!visited[i]){
            DFSrec(n, v, i);
        }
    }
    ans.push_back(node);
}

void TopoSort(int n, vector<int> v[]){
	for(int i = 1; i <= n ;i++){
		if(!visited[i]){
			DFSrec(n,v,i);
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i = 0; i  < ans.size(); i++)
	    cout << ans[i] << " ";
}

int main(){
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> v[n + 1];
	int x, y;
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		v[x].push_back(y);
	}
	memset(visited, false, sizeof(visited));
	TopoSort(n, v);
}		