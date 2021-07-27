#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function (string &s) {
  int n = s.size();
  vector<int> pre(n, 0);
  pre[0] = 0;
  for (int i = 1; i < n; i++) {
    int j = pre[i - 1];
    while (j > 0 && s[j] != s[i])
      j = p[j - 1];
    if (s[i] == s[j])
      j++;
    pre[i] = j; 
  }
  return pre;
}
