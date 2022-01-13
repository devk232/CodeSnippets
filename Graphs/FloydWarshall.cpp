#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int dis[n][n], a[n][n];
  // if a[i][j] = 0 then there is no edge between ith and jth vertex,
  // otherwise it is equal to the length of that edge.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        dis[i][j] = a[i][j];
      } else {
        dis[i][j] = 1e6;
      }
    }
  }
  for (int i = 0; i < n; i++)
    dis[i][i] = false;
  // dis[i][j] in the kth iteration denotes minimun distance between vertex i
  // and j
  // such that only first k vertices are used between these two edges.
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  bool ans = false;
  for (int i = 0; i < n; i++) {
    if (dis[i] < 0) {
      ans = false;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dis[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}