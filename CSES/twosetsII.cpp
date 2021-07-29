#include <iostream>
#define ll long long 
using namespace std;

int main(){
    int t = 1;
   // cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%4 == 0 || n%4 == 3){
            int x = n*(n + 1)/4;
            int dp[n + 1][x + 1];
            for(int i  = 0; i <= x; i++)
                dp[0][i] = 0;
            ll mod = 1e9 + 7;
            dp[0][0] = 1;
            for(int i = 1; i < n; i++){
                for(int j = 0; j <= x;j++){
                    dp[i][j] = dp[i - 1][j];
                    if(j - i >= 0){
                        dp[i][j] += dp[i - 1][j -i];
                        dp[i][j] %= mod;
                    }
                }
            }
            cout << dp[n - 1][x] << endl;
        }
        else
            cout << 0 << endl;
    }
}