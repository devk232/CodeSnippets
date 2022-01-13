#include <bits/stdc++.h>
using namespace std;

struct edge {
  int a, b, weight;
};

signed main() {
  int n, m;
  cin >> n >> m;
  edge edj[m];
  int dis[n + 1], pre[n + 1];
  for (int i = 0; i < n; i++)
    dis[i] = 1e5;
  memset(pre, -1, sizeof(pre));
  for (int i = 0; i < m; i++) {
    cin >> edj[i].a >> edj[i].b >> edj[i].weight;
  }
  int ver;
  cin >> ver;
  dis[ver] = 0, pre[ver] = -1;
  bool ok;
  for (int i = 0; i < n; i++) {
    ok = false;
    for (int j = 0; j < m; j++) {
      if (dis[edj[j].a] < 1e5) {
        if (dis[edj[j].a] + edj[j].weight < dis[edj[j].b]) {
          dis[edj[j].b] = dis[edj[j].a] + edj[j].weight;
          pre[edj[j].b] = edj[j].a;
          ok = true;
        }
      }
      if (!ok)
        break;
    }
  }
  for (int i = 0; i < n; i++)
    cout << dis[i + 1] << "\n";
  return 0;
}