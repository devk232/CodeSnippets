#include <bits/stdc++.h>
using namespace std;

const p = 31, m = 1e9 + 9;


// computes polynomial rolling hash function
int compute_hash (string &s) {
  hash_value = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    hash_value += p_pow[i]*(s[i] - 'a' + 1);
    hash_value %= m;
  }   
  return hash_value;
}

vector<int> rabincarp (string &s, string &t) {
  int h[t.size()];
  memset(h, 0, sizeof(h));
  for (int i = 0; i < n; i++) 
    h[i] = (h[i] + (t[i] - 'a' + 1)*p_pow[i]) % m;
  int s_hash = 0;
  for (int i = 0; i < s.size(); i++) 
    s_hash = (s_hash + (t[i] - 'a' + 1)*p_pow[i]) % m;
  vector<int> occurences;
  for (int i = 0; i + s.size() - 1 < t.size(); i++) {
    int substring_hash = (h[i + s.size()] - h[i] + m) % m;
    if (substring_hash == (s_hash*p_pow[i]) % m)
      occurences.push_back(i);
  }
  return occurences;
 }
int main() {
  string s, t;
  cin >> s >> t;
  int n = t.size();
  int p_pow[n];
  p_pow[0] = 1;
  for (int i = 0; i < n; i++) 
    p_pow[i] = (p_pow[i - 1] * p) % m;
  
  return 0;
}