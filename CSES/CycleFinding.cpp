#include <bits/stdc++.h>
#define ll long long 
using namespace std;

struct edge{
	ll a, b, cost;
};
int main(){
	ll n, m;
	cin >> n >> m;
	vector<edge> v(m + 1);
	vector<ll> dis(n + 1, 10000000006LL), pre(n + 1);
    ll source = 1;
    dis[source] = 0, pre[source] = n + 1;
	for(ll i = 0; i < m; i++){
		cin >> v[i].a >> v[i].b >> v[i].cost;
	}
	ll ver = -1;
	for(ll i = 0; i < n; i++){
		ver = -1;
		for(ll j = 0; j < m; j++){
			if(dis[v[j].a] + v[j].cost < dis[v[j].b]){
				dis[v[j].b] = max(-10000000006LL,dis[v[j].a] + v[j].cost);
				pre[v[j].b] = v[j].a;
				ver = v[j].b;
			}
		}
		if(ver == -1)
			break;
	}
	if(ver != -1){
		// negative cycle
		cout << "YES" << endl;
		vector<ll> ans;
		for(ll i = 0; i < n; i++)
		    ver = pre[ver];
		for(ll i = ver; ; i = pre[i]){
			ans.push_back(i);
			if(i == ver && ans.size() > 1)
				break;
		}
		reverse(ans.begin(), ans.end());
		for(ll i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
	}else{
		// no negative cycle
		cout << "NO" << endl;
	}
    return 0;
}