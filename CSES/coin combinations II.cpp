#include <iostream>
#define ll long long 
using namespace std;

int main(){
    int t = 1;
   // cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int c[n];
        for(int i = 0; i < n; i++)
            cin >> c[i];
        int dp[n + 1][x + 1];
        for(int i  = 0; i <= x; i++){
            dp[0][i] = 0;
        }
        ll mod = 1e9 + 7;
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= x;j++){
                dp[i][j] = dp[i - 1][j];
                if(j - c[i - 1] >= 0){
                    dp[i][j] += dp[i][j - c[i - 1]];
                    dp[i][j] %= mod;
                }
            }
        }
        cout << dp[n][x] << endl;
    }
}